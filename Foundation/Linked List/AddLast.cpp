    void addLast(int val) {
      // Write your code here
      if(size==0){
          Node* temp= new Node();
          temp->data=val;
          temp->next=NULL;
          head=tail=temp;
          size++;
      }
          else{
              Node* temp=new Node();
              temp->data=val;
              temp->next=NULL;
              tail->next=temp;
              tail=temp;
              size++;
          }
    }
