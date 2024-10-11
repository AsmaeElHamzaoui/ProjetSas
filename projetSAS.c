#include<stdio.h>
#include<string.h>
#define maxe 5000
#define maxD 100


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#include <windows.h>

// Fonction pour changer la couleur dans la console
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

 typedef struct{
    int annee;
    int mois;
    int jour;

}date;
  typedef struct{
    int id;
    char nom[30];
    char prenom[50];
    date naissance;
    char departement[40];
    float noteG;
   }etudiant;

 etudiant e[maxe];
 int ce=0;
 /* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><>début de foction d'initialisation<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */

  // Initialiser 10 étudiants avec des informations prédéfinies

  void initialiserE() {
    if (ce + 10 > maxe) {
        printf("Impossible d'ajouter 10 étudiants, la base est plein.\n");
        return;
    }
    char noms[10][30] = {"hafidi", "elalamy", "bentaher", "arrazi", "akziz", "essaid", "sefrawi", "karimi", "madouni", "chahbon"};
    char prenoms[10][50] = {"saida", "mariem", "kamal", "zakaria", "salim", "safae", "imane", "jalal", "farah", "hod"};
    char departements[10][40] = {"Informatique", "Mathematiques", "Physique", "Chimie", "Biologie", "Droit", "Economie", "Histoire", "Geographie", "Philosophie"};
    int annees[10] = {2000, 1999, 1998, 2001, 2002, 1997, 1996, 2000, 1995, 2003};
    int mois[10] = {1, 3, 5, 7, 9, 11, 2, 4, 6, 8};
    int jours[10] = {10, 15, 20, 5, 25, 30, 14, 18, 12, 8};
    float notes[10] = {12.5, 14.0, 16.5, 9.0, 18.0, 10.5, 7.5, 13.0, 11.5, 15.0};
    for (int i = 0; i < 10; i++) {
        e[ce].id = ce + 1;
        strcpy(e[ce].nom, noms[i]);
        strcpy(e[ce].prenom, prenoms[i]);
        e[ce].naissance.annee = annees[i];
        e[ce].naissance.mois = mois[i];
        e[ce].naissance.jour = jours[i];
        strcpy(e[ce].departement, departements[i]);
        e[ce].noteG = notes[i];
        ce++;
    }
    setColor(10);
    printf("\n 10 etudiants ont ete initialises avec succes.\n\n");
     setColor(7);
}

 /* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><>fin de foction d'initialisation<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */


 /* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><>début de foction ajouter <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */

 //ajouter un etudiant:

  void ajouterE(){
    int n;
    printf("taper le nombre d'etudiants que vous voulez ajouter : ");
    scanf("%d", &n);
    // Vérification pour ne pas dépasser la capacité
    if (ce + n > maxe) {
        printf("Impossible d'ajouter %d etudiants, le stock est plein ou depassera la capacite.\n", n);
        return;
    }
    // Ajout des étudiants dans une boucle for
    for (int i = 0; i < n; i++) {
        e[ce].id = ce + 1;
        printf("Entrer le nom de l'etudiant : ");
        scanf("%s", e[ce].nom);
        printf("Entrer le prenom de l'etudiant : ");
        scanf("%s", e[ce].prenom);
        printf("Entrer la date de naissance de l'etudiant :\n");
         // Validation de l'année de naissance
        do {
            printf("Entrer l'annee de naissance (entre 1990 et 2007) : ");
            scanf("%d", &e[ce].naissance.annee);
        } while (e[ce].naissance.annee < 1990 || e[ce].naissance.annee > 2007);
         // Validation du mois de naissance
        do {
            printf("Entrer le mois de naissance (entre 1 et 12) : ");
            scanf("%d", &e[ce].naissance.mois);
        } while (e[ce].naissance.mois < 1 || e[ce].naissance.mois > 12);
       // Validation du jour de naissance
        do {
            printf("Entrer le jour de naissance (entre 1 et 31) : ");
            scanf("%d", &e[ce].naissance.jour);
        } while (e[ce].naissance.jour < 1 || e[ce].naissance.jour > 31);
        printf("Entrer le departement : ");
        scanf("%s", e[ce].departement);
          // Validation de la note générale
        do {
            printf("Entrer la note generale (entre 0 et 20) : ");
            scanf("%f", &e[ce].noteG);
        } while (e[ce].noteG < 0 || e[ce].noteG > 20);
        ce++; // Incrémenter le compteur d'étudiants après chaque ajout
    }
    setColor(10);
    printf(" \n %d etudiants ajoutes avec succes.\n", n);
    setColor(7);
}


 /* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><> fin de foction ajouter <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */


 /* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><> début de foction modifier <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */

  //modification:
  void modifierE(){
    int ide;
    char nomModf[40];
    char prenomModf[50];
    char departementmodf[50];
    date datemodf;
    float notemodf;
    printf("entrer l'id de l'etudiant a modifer :");
    scanf("%d",&ide);
    for(int i=0;i<ce;i++){
        if(e[i].id==ide){
    printf("entrer le nom de modification :");
    scanf("%s",nomModf);
    printf("entrer le prenom de modification:");
    scanf("%s",prenomModf);
    printf("entrer la date de naissance de modification :\n");
    // Validation de l'année de naissance
            do {
                printf("Entrer l'annee de naissance de modification (entre 1990 et 2007) : ");
                scanf("%d", &datemodf.annee);
            } while (datemodf.annee < 1990 || datemodf.annee > 2007);

            // Validation du mois de naissance
            do {
                printf("Entrer le mois de naissance de modification (entre 1 et 12) : ");
                scanf("%d", &datemodf.mois);
            } while (datemodf.mois < 1 || datemodf.mois > 12);

            // Validation du jour de naissance
            do {
                printf("Entrer le jour de naissance de modification (entre 1 et 31) : ");
                scanf("%d", &datemodf.jour);
            } while (datemodf.jour < 1 || datemodf.jour > 31);
    printf("entrer le departement de modification :");
    scanf("%s",departementmodf);
   // Validation de la note générale
            do {
                printf("Entrer la note generale de modification (entre 0 et 20) : ");
                scanf("%f", &notemodf);
            } while (notemodf < 0 || notemodf > 20);
    //copier les infos modifiable dans la base de données
       strcpy(e[i].nom,nomModf);
       strcpy(e[i].prenom,prenomModf);
       e[i].naissance=datemodf;
       strcpy(e[i].departement,departementmodf);
       e[i].noteG=notemodf;
        }
    }
}

 /* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><> fin de foction modifier <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */


  /* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><> début de foction supprimer <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */

// Supprimer une tâche par ID
  void supprimerE() {
      int ide;
      printf("Entrez l'ID de l'etudiant à supprimer : ");
      scanf("%d", &ide);
    for (int i = 0; i <ce; i++) {
        if (e[i].id == ide) {
            for (int j = i; j < ce - 1; j++) {
                e[j] = e[j + 1];
            }
            ce--;
            setColor(10);
            printf("\n l'etudaint %d est supprimee avec succes.\n",i+1);
            setColor(7);
            return;
        }
    }
    printf("id non trouvee.\n");
}

  /* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><> fin de foction supprimer <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */

  /* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><> début de foction afficher <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */

  void afficherE(){
    for(int i=0;i<ce;i++){
        setColor(9);
        printf("\n l'etudiant %d est : '%s  %s' ,ne en : %d/%d/%d , inscrit au departement %s , sa note generale est %.2f \n",e[i].id,e[i].nom,e[i].prenom,e[i].naissance.jour,e[i].naissance.mois,e[i].naissance.annee,e[i].departement,e[i].noteG);
        setColor(7);
    }
}

  /* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><> fin de foction afficher <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */


  /* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><> début de foction afficher moyenne générale <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */

// Fonction pour calculer la moyenne générale par département

  void affMoyGDep() {
    float snd[maxD] = {0};//garde le somme des note pour chaque département
    int ned[maxD] = {0};//garde le nbre étudiant pour chaque département
    char departements[maxD][50];//tab pour stocker les noms des departement
    int n_departements = 0;//parcourir tout les département et ajouté au tableau  departements
    float sommeUniv = 0;//somme totale des notes de tous les étudiants
    int totalEtudiants = 0;// nbre total des etudiant

    // Parcourir les étudiants pour accumuler les notes par département
    for (int i = 0; i < ce; i++) {
        int j;
        // Vérifie si le département a déjà été enregistré
        for (j = 0; j < n_departements; j++) {
            if (strcmp(e[i].departement, departements[j]) == 0) {
                break;
            }
        }
        // Si le département est nouveau, l'ajouter à la liste
        if (j == n_departements) {
            strcpy(departements[n_departements], e[i].departement);
            n_departements++;
        }
        // Ajouter la note à la somme du département
        snd[j] += e[i].noteG;
        ned[j]++;
        // Ajouter à la somme générale de l'université
        sommeUniv += e[i].noteG;
        totalEtudiants++;
    }
        // Affichage des moyennes par département
        setColor(13);
        printf("\n Moyenne generale par departement :\n\n");
        setColor(7);
       for (int i = 0;i< n_departements; i++) {
             printf("Departement %s : ", departements[i]);
           if (ned[i] > 0) {
              printf("%.2f\n", snd[i] / ned[i]);
          } else {
              printf("Aucun etudiant.\n");
          }
    }
     // Affichage de la moyenne générale de l'université
      if (totalEtudiants > 0) {
        setColor(6);
        printf("\n Moyenne generale de l'universite : %.2f\n", sommeUniv / totalEtudiants);
        setColor(7);
      } else {
        printf("\nAucun etudiant dans l'universite.\n");
      }
}


  /* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><> fin de foction afficher moyenne générale <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */


  /* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><> début de foction rechercher  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */

//rechercher etudiant par non et par département :
  void rechercherE(){
     int n,ide;
     char dep[50];char ne[50];
     printf("taper 1 si vous vouler rechercher par nom et 2 par department :");
     scanf("%d",&n);
    if(n==1){
        printf("entrer le nom de l'etudiant recherchable :");
        scanf("%s",ne);
        for(int i=0;i<ce;i++){
            if(strcmp(e[i].nom,ne)==0){
            setColor(13);
            printf("\n l'etudiant est bien trouve voila ses information :\n");
            setColor(7);
            setColor(11);
            printf("\n l'etudiant %d son nom est : %s , son prenom : %s ,il est ne en %d/%d/%d , inscrit au departement %s , sa note generale est %.2f \n",e[i].id,e[i].nom,e[i].prenom,e[i].naissance.jour,e[i].naissance.mois,e[i].naissance.annee,e[i].departement,e[i].noteG);
            setColor(7);
            }
        }
    }
    if(n==2){
        printf("entrer le departement de l'etudiant recherchable :");
        scanf("%s",dep);
        for(int i=0;i<ce;i++){
            if(strcmp(e[i].departement,dep)==0){
            printf("\n l'etudiant est bien trouve voila ses information :\n");
            printf("\n l'etudiant %d son nom est : %s , son prenom : %s ,il est ne en %d/%d/%d , inscrit au departement %s , sa note generale est %.2f \n",e[i].id,e[i].nom,e[i].prenom,e[i].naissance.jour,e[i].naissance.mois,e[i].naissance.annee,e[i].departement,e[i].noteG);
            }
        }
    }

}

  /* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><> fin de foction rechercher  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */

  /* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><>affichage des statistiques  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */

 //1. Afficher le nombre total d'étudiants inscrits:
  void afficherStatE(){
   setColor(6);
   printf("\n Le nombre total d'etudiants inscrits est : %d\n", ce);
   setColor(7);
 //Afficher le nombre d'étudiants dans chaque département:
     int ned[maxD] = {0};
     char departements[maxD][50];
     int n_departements = 0;
      // Parcourir les étudiants
      for (int i = 0; i < ce; i++){
            int j;
            //si le département des enregistré déjà
        for (j = 0; j < n_departements; j++){
            if (strcmp(e[i].departement, departements[j]) == 0){
              break;
               }
   }
   // Si le département est nouveau
    if (j == n_departements){
            strcpy(departements[n_departements], e[i].departement);
             n_departements++;
}
// Incrémenter le compte des étudiants pour ce département
  ned[j]++; }
// Affichage du nombre d'étudiants par département
  for (int i = 0; i < n_departements; i++){
    setColor(11);
    printf(" Departement %s : %d etudiants\n", departements[i], ned[i]);
    setColor(7);
  }
//comparaision avec une seuil donnée :
    float note;
    printf("\n entrer le seuil pour afficher les etudiants inferieur a cette seuil:");
    scanf("%f",&note);
    for(int i=0;i<ce;i++){
        if(e[i].noteG<note){
         setColor(11);
         printf("\n l'etudiant %d son nom est : %s , son prenom : %s ,il est ne en %d/%d/%d , inscrit au departement %s , sa note generale est %.2f \n",e[i].id,e[i].nom,e[i].prenom,e[i].naissance.jour,e[i].naissance.mois,e[i].naissance.annee,e[i].departement,e[i].noteG);
         setColor(7);
        }
    }
  //affichage des 3 premier:

      setColor(5);
      printf("\n les 3 premeirs etudiant : \n\n");
      setColor(7);
  // Tri des étudiants par note décroissante (simple tri à bulles)
      etudiant temp;
      for (int i=0;i<ce-1; i++)
        { for (int j=0;j<ce-i-1;j++){
             if(e[j].noteG < e[j + 1].noteG){
             temp = e[j];
             e[j] = e[j + 1];
             e[j + 1] = temp;
          }
  }
  }
     for (int i = 0; i < 3 && i < ce; i++){
        setColor(11);
        printf("%s %s - Note generale: %.2f\n", e[i].nom, e[i].prenom, e[i].noteG); }
        setColor(7);

 // Afficher le nombre d'étudiants ayant réussi (note ≥ 10) dans chaque département:
      setColor(5);
      printf("\n\n le nombre d'etudiants ayant reussi (note ≥ 10) dans chaque département : \n\n");
      setColor(7);
     int com[maxD] = {0};
     char deps[maxD][50];
     int n_dep = 0;
     // Parcourir les étudiants
     for (int i = 0; i < ce; i++) {
            int j;
     for (j = 0; j < n_dep; j++)
        { if (strcmp(e[i].departement, deps[j]) == 0)
        { break; }
     }
     // Si le département est nouveau
     if (j == n_dep) {
            strcpy(deps[n_dep], e[i].departement);
     n_dep++; }
     // Vérifier si l'étudiant a réussi
     if (e[i].noteG >= 10) { com[j]++; } }
     // Affichage du nombre d'étudiants ayant réussi par département
     for (int i = 0; i < n_dep; i++){
            setColor(11);
            printf("Departement %s : %d etudiants ont reussi \n", deps[i], com[i]);
            setColor(7);
     } }
/* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><> fin d'affichage des statistiques <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */


/* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><> début des tris  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */

// 1. Tri alphabétique des étudiants par nom (A à Z ou Z à A)
  void trierSe(int ordre) {
    etudiant temp;
    for(int i=0;i<ce-1;i++){
      for(int j=i+1;j<ce;j++){
          if((ordre == 1 && strcmp(e[i].nom, e[j].nom) > 0) ||
             // Tri A à Z
             (ordre == 2 && strcmp(e[i].nom, e[j].nom) < 0)){
                 // Tri Z à A // Échange des structures complètes, donc toutes les informations restent intactes
                 temp = e[i];
                 e[i] = e[j];
                 e[j] = temp; } } }

                 // Affichage après tri
                 setColor(6);
                 printf("Etudiants tries par nom (%s):\n", ordre == 1 ? "A a Z" : "Z a A");
                 setColor(7);
                 for (int i = 0; i < ce; i++) {
                        // Toutes les informations restent intactes ici
                        setColor(11);
                        printf("ID: %d, Nom: %s, Prenom: %s, Date de naissance: %d/%d/%d, Departement: %s, Note generale: %.2f\n", e[i].id, e[i].nom, e[i].prenom, e[i].naissance.jour, e[i].naissance.mois, e[i].naissance.annee, e[i].departement, e[i].noteG);
                        setColor(7);
                        }


 // 2. Tri des étudiants par moyenne générale (du plus élevé au plus faible ou inversement)
        etudiant temp1;
            for (int i = 0; i < ce - 1; i++) {
              for (int j = i + 1; j < ce; j++) {
                if ((ordre == 1 && e[i].noteG < e[j].noteG) ||
                    // Tri du plus élevé au plus faible
                    (ordre == 2 && e[i].noteG > e[j].noteG)) {
                        // Tri du plus faible au plus élevé
                            temp1 = e[i];
                            e[i] = e[j];
                            e[j] = temp1;
                }
        }
    }
          setColor(6);
          printf("Etudiants tries par moyenne (%s):\n", ordre == 1 ? "Plus eleve au plus faible" : "Plus faible au plus eleve");
          setColor(7);
             for (int i = 0; i < ce; i++) {
                    setColor(11);
                    printf("%s %s - Note generale: %.2f\n", e[i].nom, e[i].prenom, e[i].noteG);
                    setColor(7);
             }
 // 3. Tri des étudiants selon leur statut de réussite (moyenne >= 10)
             etudiant temp2;
             for (int i = 0; i < ce - 1; i++) {
                    for (int j = i + 1; j < ce; j++) {
                        if ((e[i].noteG >= 10 && e[j].noteG < 10) || (e[i].noteG < 10 && e[j].noteG >= 10)) {
                            // Mettre les étudiants ayant réussi avant ceux qui n'ont pas réussi
                            temp2 = e[i];
                            e[i] = e[j];
                            e[j] = temp2; } } }
             setColor(6);
             printf("Etudiants tries par statut de reussite (>= 10):\n");
             setColor(7);
             for (int i = 0; i < ce; i++) {
                    setColor(11);
                    printf("%s %s - Note generale: %.2f (%s)\n", e[i].nom, e[i].prenom, e[i].noteG, e[i].noteG >= 10 ? "Reussi" : "Echoue");
                    setColor(7);
             }
    }

  /* <><><><><><><><><><><><><><><><><><><><><><><><><><>><><><> fin de tris  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  */

int main(){
    initialiserE();
    int a;
    printf("taper 1 si vous voulez ajouter :\n");
    printf("taper 2 si vous voulez modifer :\n");
    printf("taper 3 si vous voulez suppprimer :\n");
    printf("taper 4 si vous voulez afficher :\n");
    printf("taper 5 si vous voulez la note generale :\n");
    printf("taper 6 si vous voulez  afficher les statistiques :\n");
    printf("taper 7 si vous voulez rechercher :\n");
    printf("taper 8 si vous voulez  trier :\n");
    int ordre;char c;
    do{
            printf("\n entrer un chiffre selon votre choix :");
        // Vérification de l'entrée
       if (scanf("%d", &a) != 1) {
        printf("Erreur: Vous devez entrer un chiffre valide.\n");
        while (getchar() != '\n'); // Vider le buffer
        continue; // Refaire la saisie
    }
         //printf("entrer un chifre selon votre choix :");
    //scanf("%d",&a);
         switch(a){
             case 1:
             ajouterE();break;
              case 2:
             modifierE();break;
              case 3:
             supprimerE();break;
              case 4:
             afficherE();break;
              case 5:
             affMoyGDep();break;
              case 6:
             afficherStatE();break;
              case 7:
             rechercherE();break;
              case 8:{printf("entrer ordre: ");
                  scanf("%d",&ordre);
                  trierSe(ordre);break;}
             default :
             setColor(12);
             printf("\n le chifre que vous avez taper ne cercule pas dans le menu du choix :");
             setColor(7);

         }
    }while(a!=9);
}
