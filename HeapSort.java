/*Implement the Heap sort algorithm implemented in Java demonstrating heap data 
structure with modularity of programming language*/

public class HeapSort{

    public void sort(int arr[]){
        int n = arr.length;  
        for(int i = n/2 -1; i>=0; i--){
            heapify(arr, n, i);
        }
        for(int i = n-1; i>0; i--){
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }
    }

    void heapify(int arr[], int n, int i){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left<n && arr[largest]<arr[left]) largest = left;
        if(right<n && arr[largest]<arr[right]) largest = right;
        if(largest!=i){
            int temp = arr[largest];
            arr[largest] = arr[i];
            arr[i] = temp;
            heapify(arr, n, largest);
        }
    }
    
    public static void main(String args[]){
        int arr[] = {12, 11, 13, 5, 6, 7};
        int n = arr.length;
        HeapSort obj = new HeapSort();
        obj.sort(arr);
        System.out.print("Sorted Array : ");
        for(int i = 0; i<n; i++){
            System.out.print(arr[i] + " ");
        }
    }
}
