#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int puntos;
    char nombre[20];
    char nacionalidad[20];
    struct Node* left;
    struct Node* right;
};

/******************************************************FUNCIÓN******************************************************/
struct Node* newNode(char nom[20], char nac[30], int pun) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->puntos = pun;
    strcpy(node->nombre, nom);
    strcpy(node->nacionalidad, nac);
    node->left = NULL;
    node->right = NULL;
    return node;
}

/******************************************************FUNCIÓN******************************************************/
struct Node* insert(struct Node* root, char nom[20], char nac[30], int pun) {
    if (root == NULL) {
        return newNode(nom,nac,pun);
    }
    int cmp = strcmp(nom,root->nombre);
    if (cmp < 0) {
        root->left = insert(root->left, nom, nac, pun);
    } else {
        root->right = insert(root->right, nom, nac, pun);
    }
    return root;
}

/******************************************************FUNCIÓN******************************************************/
struct Node* inorder(struct Node* root, char nac[30]) {
    if (root == NULL) {
        return 0;
    }
    struct Node* Country = NULL;
    inorder(root->left,nac);
    inorder(root->right,nac);
    if (strcmp(root->nacionalidad, nac) == 0){  
        Country = insert(Country,root->nombre,root->nacionalidad,root->puntos);
        printf("\n%s\n", Country->nombre);
        printf("%s\n", Country->nacionalidad);
        printf("%d\n", Country->puntos);
        return Country;
    }
    
    
}

/******************************************************FUNCIÓN******************************************************/
void preorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d, ", root->puntos);
    printf("%s, ", root->nombre);
    printf("%s \n", root->nacionalidad);
    preorder(root->left);
    preorder(root->right);
}

/******************************************************FUNCIÓN******************************************************/
void postorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d, ", root->puntos);
    printf("%s, ", root->nombre);
    printf("%s \n", root->nacionalidad);
}

/******************************************************FUNCIÓN******************************************************/
int search(struct Node* root, char nom[20],char nac[30]) {
    if (root == NULL) {
        return 0;
    }
    if (strcmp(root->nombre, nom) == 0){
        return 1;    
    } 
    if (strcmp(nom, root->nombre) < 0){
        return search(root->left, nom,nac);
    }
    return search(root->right, nom,nac);
}

/******************************************************FUNCIÓN******************************************************/
int searchCountry(struct Node* root, char nac[30]) {
    if (root == NULL) {
        return 0;
    }
    if (strcmp(root->nacionalidad, nac) == 0){
        return 1;
    } 
    if (strcmp(nac, root->nacionalidad) < 0){
        return searchCountry(root->left, nac);
    }
}


int main() {
    char name[20], pais[30];

    struct Node* Gold = NULL;
    Gold = insert(Gold, "esmeralda","colombia",10);
    Gold = insert(Gold, "alejandra","mexico",10);
    Gold = insert(Gold, "ryan","usa",10);
    Gold = insert(Gold, "harry","england",10);
    Gold = insert(Gold, "leonel","argentina",10);
    Gold = insert(Gold, "michael","usa",10);
    Gold = insert(Gold, "alberto","colombia",10);
    Gold = insert(Gold, "zoraida","mexico",10);
    Gold = insert(Gold, "james","england",10);
    Gold = insert(Gold, "angela","mexico",10);
    Gold = insert(Gold, "sophia","russia",10);
    Gold = insert(Gold, "venacio","italy",10);
    Gold = insert(Gold, "hermionie","england",10);//

    struct Node* Silver = NULL;
    Silver = insert(Silver, "jesus","mexico",5);
    Silver = insert(Silver, "micaela","argentina",5);
    Silver = insert(Silver, "manuel","colombia",5);
    Silver = insert(Silver, "jose","mexico",5);
    Silver = insert(Silver, "luis","colombia",5);
    Silver = insert(Silver, "eric","colombia",5);
    Silver = insert(Silver, "jill","usa",5);
    Silver = insert(Silver, "marcus","usa",5);
    Silver = insert(Silver, "harry","england",5);
    Silver = insert(Silver, "tyler","usa",5);
    Silver = insert(Silver, "ronald","usa",5);
    Silver = insert(Silver, "donald","italy",5);
    Silver = insert(Silver, "catherine","usa",5);
    Silver = insert(Silver, "antonietta","russia",5);
    Silver = insert(Silver, "charles","england",5);//

    struct Node* Bronze = NULL;
    Bronze = insert(Bronze, "cristobal","colombia",2);
    Bronze = insert(Bronze, "emilia","mexico",2);
    Bronze = insert(Bronze, "rita","colombia",2);
    Bronze = insert(Bronze, "lisa","argentina",2);
    Bronze = insert(Bronze, "rual","colombia",2);
    Bronze = insert(Bronze, "brian","usa",2);
    Bronze = insert(Bronze, "jennifer","usa",2);
    Bronze = insert(Bronze, "george","england",2);
    Bronze = insert(Bronze, "william","england",2);
    Bronze = insert(Bronze, "jessica","mexico",2);
    Bronze = insert(Bronze, "sarah","russia",2);
    Bronze = insert(Bronze, "oliver","russia",2);
    Bronze = insert(Bronze, "thea","usa",2);
    Bronze = insert(Bronze, "mario","italy",2);
    Bronze = insert(Bronze, "greta","russia",2);
    Bronze = insert(Bronze, "giancarlo","italy",2);
    Bronze = insert(Bronze, "shanon","usa",2);
    Bronze = insert(Bronze, "melisa","mexico",2);
    Bronze = insert(Bronze, "porfirio","mexico",2);
    Bronze = insert(Bronze, "aurora","colombia",2);
    Bronze = insert(Bronze, "daniele","england",2);
    Bronze = insert(Bronze, "nola","usa",2);
    Bronze = insert(Bronze, "nina","russia",2);

    printf("Ingrese un nombre a buscar: (en minusculas)\n");
    scanf("%s",&name);
    fflush(stdin);

    printf("Ingrese su pais: (en minusculas)\n");
    scanf("%s",&pais);
    fflush(stdin);
   
    struct Node* team1 = NULL;
    struct Node* team_of = NULL;
    
    if (search(Gold, name,pais) ){
        inorder(Gold,pais);
        //team_of=insert(team1,team1->nombre,team1->nacionalidad,team1->puntos);
        if (searchCountry(Silver, pais)){
            inorder(Silver,pais);
            //team_of=insert(team1,team1->nombre,team1->nacionalidad,team1->puntos);
        }if (searchCountry(Bronze, pais)){
            inorder(Bronze,pais);
            //team_of=insert(team1,team1->nombre,team1->nacionalidad,team1->puntos);
        }
    }

    if (search(Silver, name,pais) ){
        inorder(Silver,pais);
        //team_of=insert(team1,team1->nombre,team1->nacionalidad,team1->puntos);
            if (searchCountry(Bronze, pais)){
            inorder(Bronze,pais);
            //team_of=insert(team1,team1->nombre,team1->nacionalidad,team1->puntos);
        }if (searchCountry(Gold, pais)){
            inorder(Gold,pais);
            //team_of=insert(team1,team1->nombre,team1->nacionalidad,team1->puntos);
        }
    }

    if (search(Bronze, name,pais) ){
        inorder(Bronze,pais);
        //team_of=insert(team1,team1->nombre,team1->nacionalidad,team1->puntos);
            if (searchCountry(Silver, pais)){
            inorder(Silver,pais);
            //team_of=insert(team1,team1->nombre,team1->nacionalidad,team1->puntos);
        }if (searchCountry(Gold, pais)){
            inorder(Gold,pais);
            //team_of=insert(team1,team1->nombre,team1->nacionalidad,team1->puntos);
        }
    }
    return 0;
}