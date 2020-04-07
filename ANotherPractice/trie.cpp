#include<bits/stdc++.h>


struct trie_node{
	trie_node *next, *child;
	char letter;
	trie_node(){
		letter = '$';
		next = nullptr;
		child = nullptr;
	}

};



void insert(trie_node* cur, std::string s, int i)
{
	if(i>=s.size())
		return;
	if(cur->next==nullptr && cur->child == nullptr){
		cur->letter = s[i];
		cur->next = new trie_node();
		insert(cur->next, s, i+1);
	}
	else if(cur->letter == s[i]){
		if(cur->next==nullptr)
			cur->next = new trie_node();
		insert(cur->next, s, i+1);
	}
	else{
		if(cur->child==nullptr)
			cur->child = new trie_node();
		insert(cur->child, s, i);	
	}
}

bool search(trie_node* cur,std::string s, int i)
{
	if(cur->letter=='$' || i>=s.size()){
		return 1;
	}
	else if(cur->next==nullptr && cur->child==nullptr){
		return 0;
	}
	else{
		std::cout<<cur->letter;
		if(cur->letter==s[i])
			return search(cur->next,s,i+1);
		else
			return search(cur->child,s,i);
	}
}

int main(){
	std::vector<std::string> s{"bank","bad","banked","box","dad","dance"};
	trie_node *root = new trie_node();
	for(auto i:s)
		insert(root,i,0);
	auto temp = root;
	/*while(temp){
		std::cout<<temp->letter;
		temp = temp->next;
	}*/
	std::cout<<'\n'<<search(root, "dance", 0);
}