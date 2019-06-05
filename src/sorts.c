/**
 * 函数名称:bubbleSort
 * 函数描述:冒泡排序
 * 编写时间:2019-06-05
 * 作者: qingyu
 */
void bubbleSort(int* arr, int size){
    if (size <= 1)
        return;
    int i,j;
    for ( i = 0; i < size; i++)
    {
        int flag = 0;
        for (j = 0; j < size -1 -i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                arr[j] = arr[j] ^ arr[j+1];
                arr[j+1] = arr[j] ^ arr[j+1];
                arr[j] = arr[j] ^ arr[j+1];
                flag = 1;
            }
        }
        if (!flag)
            break;   
    }
}

/**
 * 函数名称:insertSort
 * 函数描述:插入排序
 * 编写时间:2019-06-05
 * 作者: qingyu
 */
void insertSort(int* arr, int size){
    if (size<=1)
        return;
    int i,j;
    for ( i=1; i < size; i++)
    {
        int val = arr[i];
        for ( j=i-1; j>=0 ; j--)
        {
            if (arr[j] > val )
                arr[j+1] = arr[j];
            else
                break; 
        }
        arr[j+1] = val;  
    }   
}

/**
 * 函数名称:selectSort
 * 函数描述:选择排序
 * 编写时间:2019-06-05
 * 作者: qingyu
 */
void selectSort(int* arr, int size){
    if (size <=1)
        return;
    int i,j;
    for ( i=0; i<size-1; i++)
    {
        int min=i;
        for ( j=i+1; j<size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            } 
        }
        if (i!=min)
        {
            arr[i] = arr[i] ^ arr[min];
            arr[min] = arr[i] ^ arr[min];
            arr[i] = arr[i] ^ arr[min];  
        }
    }
}

/**
 * 函数名称:quickSort
 * 函数描述:快速排序
 * 编写时间:2019-06-05
 * 作者: qingyu
 */
void quickSort(int *arr, int left, int right){
    if (left >= right)
    {
        return;
    }
    int i=left, j=right,p=left;
    while (i<j)
    {
        for ( ; arr[j] >= arr[i] && i<j; j--);
        if (i==j){
            break;
        }
        else
        {
            arr[i] = arr[i] ^ arr[j];
            arr[j] = arr[i] ^ arr[j];
            arr[i] = arr[i] ^ arr[j];
            p=j;
        }
        for ( ; arr[i] <= arr[j] && i<j; i++);
        if (i==j)
        {
            break;
        }
        else
        {
            arr[i] = arr[i] ^ arr[j];
            arr[j] = arr[i] ^ arr[j];
            arr[i] = arr[i] ^ arr[j];
            p=i;
        }   
    }
    quickSort(arr, left, p-1);
    quickSort(arr, p+1, right);
}