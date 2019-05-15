/*
Program		: exercise-02
Nama		: Sitti Ufairoh Azzahra
NPM			: 140810180002
Deskripsi	: Binary Search Tree
Tanggal		: 15 Mei 2019
*/

#include<iostream>
using namespace std;

struct Simpul{
    int info;
    Simpul* left;
    Simpul* right;
};
typedef Simpul* pointer;
typedef pointer Tree;

void createSimpul(pointer& pBaru){
    pBaru=new Simpul;
    cout<<"Masukkan satu angka : ";
    cin>>pBaru->info;
    pBaru->left=NULL;
    pBaru->right=NULL;
}

void insertBST (Tree& Root, pointer pBaru){
    if(Root==NULL){
        Root=pBaru;
    }
    else if (pBaru->info < Root->info){
        insertBST(Root->left,pBaru);
    }
    else if (pBaru->info > Root->info){
        insertBST(Root->right,pBaru);
    }
    else{
        cout<<"Sudah ada"<<endl;
    }
}

void preOrder (Tree Root) {
    if (Root != NULL){
        cout<< Root->info <<endl;
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

void inOrder (Tree Root) {
    if (Root != NULL){
        inOrder(Root->left);
        cout<< Root->info <<endl;
        inOrder(Root->right);
    }
}

void postOrder (Tree Root) {
    if (Root != NULL){
        postOrder(Root->left);
        postOrder(Root->right);
        cout<< Root->info <<endl;
    }
}


int height(Tree Root){
    if (Root==NULL) return 0;
    else{
        int lHeight=height(Root->left);
        int rHeight=height(Root->right);

        if (lHeight>rHeight) return (lHeight+1);
        else return (rHeight+1);
    }
}


void givenLevel(Tree Root, int level){
    if (Root==NULL) 
        return;
    if (level==1) 
        cout << Root->info << " ";
    else if (level>1){
        givenLevel(Root->left,level-1);
        givenLevel(Root->right,level-1);
    }
}

void kedalaman(Tree Root){
    int h=height(Root);
    for (int i=1; i<=h; i++){
        cout << i-1 << ": " <<" [ ";
        givenLevel(Root,i);
        cout<< "]"<< endl;
    }
}

void levelOrder(Tree Root){
    int h=height(Root);
    for (int i=1; i<=h; i++){
        cout << i << ": " <<" [ ";
        givenLevel(Root,i);
        cout<< "]"<< endl;
    }
}

void Anak(Tree Root, pointer pBaru){
    pBaru= Root;
    if(pBaru!=NULL){
        cout<<"Parent Node = "<<pBaru->info<<endl;
        if(pBaru->left == NULL)
            cout<<"Left Child = NULL"<<endl;
        else
            cout<<"Left Child = "<<pBaru->left->info<<endl;
                     
        if(pBaru->right == NULL)
            cout<<"Right Child = NULL"<<endl;
        else
            cout<<"Right Child = "<<pBaru->right->info<<endl;
		
		cout<<endl;
        Anak(Root->left, pBaru);
        Anak(Root->right, pBaru);
    }
}

int main(){
    Tree Root;
    pointer p;
    int pil, n;
    char ans;
	Root=NULL;
	
    cout<<"\tTREE"<<endl;
    cout<<"Masukkan banyak data :"; cin>>n; //masukkin 15
    for (int i=0;i<n;i++){ 
        createSimpul(p);
        insertBST(Root,p); 
		//input 7 11 3 4 5 9  12 15 1 10 2 25 8 14 19
    }
    do{
        system("CLS");
    	cout<<"\tMENU"<<endl;
    	cout<<"====================="<<endl;
    	cout<<"[1] Insert BST"<<endl;
    	cout<<"[2] Preorder"<<endl;
    	cout<<"[3] Inorder"<<endl;
    	cout<<"[4] Postorder"<<endl;
    	cout<<"[5] Kedalaman"<<endl;
    	cout<<"[6] Level"<<endl;
    	cout<<"[7] Anak"<<endl;
    	cout<<"[8] Exit"<<endl;
    	cout<<"====================="<<endl;
    	cout<<"Pilihan : ";cin>>pil;

    switch(pil){
    	case 1:
    		cout<<"\nInsert BST "<<endl;
        	createSimpul(p);
        	insertBST(Root,p);
        	
        case 2:
        	cout<<"\nPREORDER"<<endl;
        	preOrder(Root);
        	break;
        
        case 3:
        	cout<<"\nINORDER"<<endl;
        	inOrder(Root);
       	 	break;
        
        case 4:
        	cout<<"\nPOSTORDER"<<endl;
        	postOrder(Root);
        	break;

  		case 5:
        	cout<<"\nKEDALAMAN"<<endl;
        	kedalaman(Root);
        	break;
        	
        case 6:
        	cout<<"\nLEVEL"<<endl;
        	levelOrder(Root);
        	break;
        	
        case 7:
        	cout<<"ANAK"<<endl;
            Anak(Root, p);
            break;
            
		case 8:
            cout<<"\nOke Sudah selesai, Terima Kasih :) "<<endl;
            return 0;
            break;
					
        default:
        	cout<<"MAMPUS SALAH NGASAL INPUT SIH!!"<<endl;
        break;
    }
    cout<<"Kembali ke menu?(Y/N)"; cin>>ans;
}
while(ans=='y'|| ans=='Y');
}
