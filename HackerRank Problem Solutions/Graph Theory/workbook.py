def workbook(n, k, arr):
   
    special_problems = []
    page_count = 1
    for chap in range(1,n+1):
        n_probs = arr[chap-1]
        n_pages_in_chap = (n_probs + k - 1) // k
        max_probs = k * n_pages_in_chap
        for i in range(1, n_probs+1):
            if i == page_count:
               special_problems.append(page_count)
            if (i % k == 0):
               page_count += 1
            if (n_probs == i) and (i < max_probs):
               page_count += 1
    return len(special_problems)
