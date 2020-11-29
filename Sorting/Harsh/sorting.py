#SELECTION SORT::

k=len(arr)
arr=list(map(int,input().split()))           
                                        
for i in range(0,k-1): 
    minpos=i                             
    for j in range(i,k):
        if arr[j]<arr[minpos]:
            minpos=j
    arr[i],arr[minpos]=arr[minpos],arr[i]
print(arr)

##############################################################

#BUBBLE SORT::

arr=list(map(int,input().split()))
k=len(arr)
                                        
for i in range(k-1,0,-1):
    for j in range(i):
        if arr[j]>arr[j+1] :
            arr[j],arr[j+1]=arr[j+1],arr[j]
print(arr) 

###########################################################################

#INSERTION SORT::

arr=list(map(int,input().split()))
for index in range(1,len(arr)):
        value=arr[index]
        i=index-1
        while i>=0:
            if value<arr[i]:
                arr[i+1]=arr[i]
                arr[i]=value
                i=i-1
            else:
                break
print(arr)

########################################################################

#QUICK SORT::

def quick_sort(arr):
    k=len(arr)
    if k<=1:
        return arr
    else:
        pivot=arr.pop()
        smaller=[]
        greater=[]
        for i in arr:
            if i<pivot:
                smaller.append(i)
            if i>pivot:
                greater.append(i)

        return quick_sort(smaller) +[pivot] +quick_sort(greater)



arr=list(map(int,input().split()))
k=len(arr)
alpha=quick_sort(arr)
print(alpha)

###############################################################################
                                        
# MERGE SORT::
	def merge(arr,brr):           #merging two arrays in a sorted array
    i=0
    j=0
    res=[]
    while i<len(arr) and j<len(brr):
        if arr[i]<=brr[j]:
            res.append(arr[i])
            i+=1
        else:
            res.append(brr[j])
            j+=1
    while i<len(arr):
        res.append(arr[i])
        i+=1
    while j<len(brr):
        res.append(brr[j])
        j+=1
    return res

def mergesort(arr):      #  merge sort()
    if len(arr)==1:
        return arr
    mid=len(arr)//2
    left=mergesort(arr[:mid])
    right=mergesort(arr[mid:])
    return merge(left,right)

arr=list(map(int,input().split()))
print(*mergesort(arr))


