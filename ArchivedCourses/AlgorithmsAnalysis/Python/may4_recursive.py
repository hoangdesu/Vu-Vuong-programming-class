def hi(num):
    # base case
    if num > 10:
        return
    
    print('hi', num)
    hi(num + 1)

hi(1)