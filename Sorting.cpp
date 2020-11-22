#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
#include<time.h>
using namespace std;
void display(int arr[],int s)
{cout<<endl<<"Array after sorting:";
 for(int i=0;i<s;i++)
  cout<<arr[i]<<" ";
}
void insertion(int arr[],int s)
{ cout<<"Insertion sort:\n";
  for(int i=1;i<s;i++)
  { int t=arr[i];
    for(int j=i-1;j>=0&&t<arr[j];j--)
    { arr[j+1]=arr[j];
      arr[j]=t;
    }
    cout<<"\nArray after pass "<<i<<":";
    for(int k=0;k<s;k++)
    cout<<arr[k]<<" ";
  }
}
void bubble(int arr[],int s)
{ cout<<"Bubble sort:\n";
   for(int i=0;i<s-1;i++)
  { for(int j=1;j<s;j++)
     { if(arr[j]<arr[j-1])
       {int temp=arr[j];
        arr[j]=arr[j-1];
        arr[j-1]=temp;
       }
     }
    cout<<"\nArray after pass "<<i+1<<":";
    for(int k=0;k<s;k++)
     cout<<arr[k]<<" ";
  }
}
void selection(int arr[],int s)
{ cout<<"Selection sort:\n";
  for(int i=0;i<s-1;i++)
  { int min=i;
    for(int j=i+1;j<s;j++)
     if(arr[i]>arr[j])
      min=j;
     if(min!=i)
    {int temp=arr[min];
     arr[min]=arr[i];
     arr[i]=temp;
    }
    cout<<"\nArray after pass "<<i+1<<":";
    for(int k=0;k<s;k++)
    cout<<arr[k]<<" ";
  }
}
void counting(int a[],int s)
{ cout<<"Counting sort:\n";
  int i,max=a[0];
  for(i=1;i<s;i++)
   if(a[i]>max)
     max=a[i];
   int output[s],count[max+1];
    for(i=0;i<=max;i++)
      count[i]=0;
    for(i=0;i<s;i++)
      count[a[i]]+=1;
    for(i=1;i<=max;i++)
      count[i]+=count[i-1];
    for(i=0;i<s;i++)
    {output[count[a[i]]-1]=a[i];
     count[a[i]]-=1;
    }
    for(i=0;i<s;i++)
     cout<<output[i]<<" ";
}
void radix(int arr[],int s)
{ cout<<"Radix sort:\n";
  int i,max=arr[0],ps=0;
  for(i=1;i<s;i++)
   if(arr[i]>max)
     max=arr[i];
  for(i=1;max/i>0;i*=10)
  { for(int k=1;k<s;k++)
   { int t=arr[k];
     for(int j=k-1;j>=0 && (((t/i)%10)<((arr[j]/i)%10));j--)
     { arr[j+1]=arr[j];
       arr[j]=t;
     }
   }
    cout<<"\nArray after pass "<<++ps<<":";
    for(int m=0;m<s;m++)
    cout<<arr[m]<<" ";
  }
}
void bucket(int arr[],int s)
{ vector<int> bucket[s];
   int i,max=arr[0];
  for(i=1;i<s;i++)
   if(arr[i]>max)
     max=arr[i];
  for(i=0;i<s;i++)
    bucket[int(((s-1)*arr[i])/max)].push_back(arr[i]);
  for(i=0;i<s;i++)
   for(int m=1;m<bucket[i].size();m++)
  { int t=bucket[i][m];
    for(int j=m-1;j>=0&&t<bucket[i][j];j--)
    { bucket[i][j+1]=bucket[i][j];
      bucket[i][j]=t;
    }
  }
   int index=0;
    for(i=0;i<s;i++)
     for(int j=0;j<bucket[i].size();j++)
       arr[index++]=bucket[i][j];
  cout<<"\nArray after bucket sort:\n";
  for(i=0;i<s;i++)
   cout<<arr[i]<<" ";
}
void mergearr(int arr[],int p,int q, int r)
{int n1=q-p+1;
 int n2=r-q;
 int arrL[n1],arrR[n2],i,j,k;
 cout<<"\nInitial sub-array:";
 for(int l=p;l<=r;l++)
    cout<<arr[l]<<" ";
 cout<<"\nLeft array:";
 for(i=0;i<n1;i++)
 {arrL[i]=arr[p+i];
  cout<<arrL[i]<<" ";
 }
 cout<<"\nRight array:";
 for(j=0;j<n2;j++)
 {arrR[j]=arr[q+j+1];
  cout<<arrR[j]<<" ";
 }
  i=0;
  j=0;
  k=p;
  int swap_c=0;
  while(i<n1 && j<n2)
  {if (arrL[i] <= arrR[j])
   {arr[k]=arrL[i];
    i++;
   }
   else {arr[k]=arrR[j];
         swap_c+=abs(q+j+1-k);  //p-i
         j++;
        }
   k++;
  }
  while(i < n1)
    { arr[k]=arrL[i];
      i++;
      k++;
    }
  while(j<n2)
  {arr[k] =arrR[j];
   j++;
   k++;
  }
  cout<<"\nDebug o/p:"<<"p="<<p<<" q="<<q<<" r="<<r<<" swaps="<<swap_c<<endl;
  for(int m=p;m<=r;m++)
    cout<<arr[m]<<" ";
}
void mergesort(int arr[],int p,int r)
{if(p<r)
 {int q=p+(r-p)/2;
  mergesort(arr,p,q);
  mergesort(arr,q+1,r);
  mergearr(arr,p,q,r);
 }
}
int qs_partition(int arr[],int li,int hi)
{int i=li-1,pivot=arr[hi],j;
 for(j=li;j<hi;j++)
    if(arr[j]<pivot)
  { i++;
    swap(arr[i],arr[j]);
  }
  swap(arr[i+1],arr[hi]);
 cout<<endl<<"After partition:";
 for(j=li;j<=hi;j++)
  cout<<arr[j]<<" ";
 return i+1;
}
void quicksort(int arr[],int li,int hi)
{ if(li<hi)
 {int pi=qs_partition(arr,li,hi);
  quicksort(arr,li,pi-1);
  quicksort(arr,pi+1,hi);
 }
}
int rand_partition(int arr[],int p,int r)
{int q=(rand()%(r-p+1))+p;
  swap(arr[p],arr[q]);
 return qs_partition(arr,p,r);
}
void rand_quicksort(int arr[],int li,int hi)
{ if(li<hi)
 {srand(time(0));
  int pi=rand_partition(arr,li,hi);
  rand_quicksort(arr,li,pi-1);
  rand_quicksort(arr,pi+1,hi);
 }
}
void max_heapify(int arr[],int i,int n)
{int l=2*i+1; //left child
 int r=2*i+2; //right child
 int largest=0;
 if(l<=n && arr[l]>arr[i])
  largest=l;
 else largest=i;
 if(r<=n && arr[r]>arr[largest])
    largest=r;
 if(largest!=i)
 {swap(arr[i],arr[largest]);
  max_heapify(arr,largest,n);
 }
}
void build_max_heap(int arr[],int n)
{for(int i=floor(n/2);i>=0;i--)
  //call for all leaf nodes
  max_heapify(arr,i,n);
}
void heapsort(int arr[],int n)
{build_max_heap(arr,n);
 for(int i=n;i>=1;i--)
 { swap(arr[0],arr[i]);
   n--;
   max_heapify(arr,0,n);
 }
}
int main()
{ int input;
  char ch;
  do
 {int n;
  cout<<"\nEnter size of array:";
  cin>>n;
  int arr[n];
  cout<<"Enter array elements:";
  for(int i=0;i<n;i++)
   cin>>arr[i];
  cout<<"\n----SORTING MENU----";
  cout<<"\n1.Insertion sort";
  cout<<"\n2.Selection sort";
  cout<<"\n3.Bubble sort";
  cout<<"\n4.Counting sort";
  cout<<"\n5.Radix sort";
  cout<<"\n6.Bucket sort";
  cout<<"\n7.Merge sort";
  cout<<"\n8.Quick sort";
  cout<<"\n9.Randomize Quick sort";
  cout<<"\n10.Heap sort";
  cout<<"\nEnter your choice:";
  cin>>input;
  switch(input)
  {
     case 1: insertion(arr,n);
             break;
     case 2: selection(arr,n);
             break;
     case 3: bubble(arr,n);
             break;
     case 4: counting(arr,n);
             break;
     case 5: radix(arr,n);
             break;
     case 6: bucket(arr,n);
             break;
	 case 7:mergesort(arr,0,n-1);
	        display(arr,n);
            break;
     case 8:quicksort(arr,0,n-1);
	        display(arr,n);
            break;
     case 9:rand_quicksort(arr,0,n-1);
	        display(arr,n);
            break;
     case 10:heapsort(arr,n);
	        display(arr,n);
            break;
     default: cout<<"Wrong Input!";
  }
  cout<<"\nDo you want to go again?(y/n)";
  cin>>ch;
 }while(ch!='n');
  return 0;
}
