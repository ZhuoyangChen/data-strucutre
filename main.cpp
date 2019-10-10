//filename: suffix_tree.cpp
//to build a suffix tree based on the given string ending with $

#include <iostream>
#include <cstring>

using namespace std;

struct node
{
    char *str;
    node *child[27];
};

node* add_node(char *s)
{
    node *tmp = new node;
    tmp->str = s;
    for(int i=0;i<27;i++)
        tmp->child[i]=NULL;
}

int searchnode(node* N)//return the next empty child
{
    for(int i=0;i<27;i++)
    {
        if(N->child[i]== NULL)
            return i;
    }
}

char* substring(char *s, int start, int num)
{
    int n = strlen(s);
    char *tmp = new char[n];
    for(int i=0;i<num;i++)
    {
        tmp[i] = s[start+i];
    }
    tmp[num] = '\0';

    return tmp;
}

int IsSubstr(char*s1,char*s2)//assume that s2 is shorter than s1
{
    if(!strcmp(s1,s2)) return 0;//totally match
    int n=strlen(s2);
    if(s1[0]!=s2[0]) return -1;//not match
    else return 1;//substring at least at position 1
}

int match(char*ch, char*s)
{
    if(!IsSubstr(ch,s)) return 0;//match do nothing

    if(strlen(ch)<strlen(s)||strlen(ch)==strlen(s))//not completely match
    {
        if(IsSubstr(s,ch)!=1)//child is not a substring of s
            return -1;//not match
        else//child is a substring
        {
            for(int i=0;i<strlen(ch);i++)
            {
                if(ch[i]!=s[i])
                    return i;//return the position that child not match with s
            }
        }
    }
    else if(strlen(ch)> strlen(s))
    {
        if(IsSubstr(ch,s)!=1)
            return -1;//not match
        else
        {
            for(int i=0;i<strlen(s);i++)
            {
                if(ch[i]!=s[i])
                    return i;//return the position that child not match with s
            }
        }
    }

    else return -1;//not match or substring match
}

node* searchpattern(node *root, char *s)
{
    if(!root) return NULL;
    else
    {
        int i=0;
        while(root->child[i])
        {
            if(root->child[i]->str[0]==s[0])
            {
                node *tmp = root->child[i];
                return tmp;
            }
            i++;
        }
    }
    return NULL;
}


void suffix_tree(node *root, char*s)
{
    int n=strlen(s);
    node *N = searchpattern(root,s);
    if(!N) root->child[searchnode(root)] = add_node(s);//pattern not found
    else
    {
        int k = match(N->str,s);
        char *sub = substring(N->str, k, strlen(N->str)-k);
        if(sub[strlen(sub)-1]=='$'&&sub!="")//leaf
        {
                suffix_tree(N,sub);//root difference
                N->str = substring(N->str,0,k);//root string remain
                s = substring(s, k, n-k);
                if(s!="") suffix_tree(N,s);//pattern remain
        }
        else//middle node
        {
                int j=searchnode(N);
                if(sub!="") N->child[j] = add_node(sub);

                for(int i=0;i<j;i++)
                {
                    N->child[j]->child[i] = N->child[i];
                    N->child[i] = NULL;
                }
                N->child[0] = N->child[j];
                N->child[j] = NULL;

                N->str = substring(N->str,0,k);//root string remain
                s = substring(s, k, n-k);
                if(s!="") suffix_tree(N,s);//pattern remain
        }
    }
}

void display(node *root, int n)
{
    if(root)
    {
        for(int i=0;i<n;i++)
        {
            display(root->child[i],n);
        }
        cout << root->str << endl;
    }
}

int main()
{
    char *s = "banana$";
    int n = strlen(s);

    node *root = add_node("+");

    for(int i=0;i<n;i++)
    {
        suffix_tree(root,substring(s,i,n-i));
        //display(root,n);
    }

    display(root, n);

    return 0;
}
