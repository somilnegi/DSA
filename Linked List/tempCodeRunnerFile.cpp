        }
        curr=curr->next;
    }
    odd->next=nullptr;
    even->next=temp2;
    return temp1;
}