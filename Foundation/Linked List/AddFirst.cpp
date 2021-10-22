    public void addFirst(int val) {
      // write your code here
      Node* temp= new Node();
      temp->data=val;
      if(size==0){
      head=tail=temp;
      temp->next=null;
      size++;
      }
      else{
      temp->next=head;
      head=temp;
      size++;
    }
    }
