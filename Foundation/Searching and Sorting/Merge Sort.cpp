/* Merge two sorted arrays
int i=0;
int j=0;
int k=0;
while(i<a.length && j<b.length){
  if(a[i]<a[j]){
    res[k]=a[i];
    i++;
    k++;
  }
  else{
     res[k]=a[j];
    j++;
    k++;
  }
}
  while(i<a.length){
    res[k]=a[i];
    i++;
    k++;
  }
   while(j<b.length){
    res[k]=a[j];
    j++;
    k++;
   }
  return res;
}

*/

//MERGE SORT
