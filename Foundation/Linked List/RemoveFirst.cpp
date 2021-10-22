    public void removeFirst(){
      // write your code here
      if(size==0)
      cout<<"List is empty";
      else if(size==1)
      {head=tail=NULL;
      size=0;
      }
      else{
      head=head->next;
      size--;
      }
    }
  }
