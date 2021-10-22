public int size(){
      // write code here
      return size;
    }

    public void display(){
      // write code here
      Node* temp=head;
      while(temp!=NULL){
          cout<<temp->data<<" ";
      temp=temp->next;
    }
        cout<<"\n";
    }
    
  
