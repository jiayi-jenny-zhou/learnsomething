def max_area(height):
    max_area = 0
    n = len(height)

    hsorted = []
    for i in range(0,n):
        hsorted.append((height[i],i))
    hsorted.sort()

    begin = 0
    end = n-1
    for h in hsorted:
        while(height[begin] < h[0]):
            begin = begin+1
        while(height[end]<h[0]):
            end = end-1

        area = h[0]*max(end-h[1], h[1]-begin)
        if area>max_area:
            max_area = area

    return max_area
