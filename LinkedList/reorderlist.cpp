// you are given with linked list you have to reorder it like that
// eg.1 input :  1 2 3 4
//      output : 1 4 2 3
// eg.2 input : 1 2 3 4 5 
//      output: 1 5 2 4 3 

class Solution {
public:
    void reorderList(ListNode* head) {

        if(!head || !head->next) return ;
        
        vector<ListNode*>v;
        ListNode*temp=head;
        while(temp!=NULL){
            v.push_back(temp);
            temp=temp->next;
        }
        int i=0,j=v.size()-1;

        while(i<j){
            v[i]->next=v[j];
            cout<<v[i]->val<<"->"<<v[j]->val<<endl;
            i++;
            if(i==j) break;
            v[j]->next=v[i];
            cout<<v[j]->val<<"->"<<v[i]->val<<endl;
            j--;
        }

        v[i]->next=NULL;
           
    }
};