/* Partition of ana rray

0 to j-1 ->  <= pivot
j to i-1 ->   > pivot
i to end -> unknown area

int i=0;
int j=0;
while(i< arr.length){
if(arr[i]> pivot)
i++;
else{
swap(arr,i,j)
i++;
j++;
}
