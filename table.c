//Anastasis Drougas
//it2024023
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//All the functions that we use.
int linear_search(char item[118][50],int size, char item_choise[50]); //Linear search to find the given name or symbol.
int binary_search(int atomic_number[],int size,int atomic_n_choise); //Binary search to find the given atomic number.
void F3(int position,char name[118][50],char symbol[118][50],char chemical_group[118][50],double atomic_mass[118]);//Third monitor
void clearmonitor();//Function that clears the monitor.
int answer_scan_check(int answer);//Answer check for F1 & F2 function.
int F1(int answerF1); //First monitor.
int F2(int answerF2,char name[118][50],char symbol[118][50],char chemical_group[118][50],double atomic_mass[118],int atomic_number[118]); // Second monitor.
int F5(int min_a_n,int max_a_n,char cg[50],float min_a_mass,float max_a_mass,char table[118][10],int atomic_number[118],char chemical_group[118][50],double atomic_mass[118]);//Fifth monitor.
void F4(int answerF4,char chemical_group[118][50],char table[118][10],char name[118][50],char symbol[118][50],int atomic_number[118],double atomic_mass[118]);//Fourth monitor.

int main()
{
    char name[118][50] = {
    "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon",//Array for the element names.
    "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium",
    "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc",
    "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium",
    "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin",
    "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium",
    "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium",
    "Lutetium", "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury",
    "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium",
    "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium",
    "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium",
    "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"};
    
    char symbol[118][50]={"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",//Array for the element symbols.
        "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
        "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
        "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
        "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
        "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
        "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
        "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
        "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
        "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
        "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
        "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
    
    int atomic_number[118]; //Making the array that has the atomic numbers.
    for (int i = 0; i < 118; i++)
    {
        atomic_number[i] = i + 1;
    }

    double atomic_mass[118]={1.0080, 4.00260, 7.0, 9.012183, 10.81, 12.011, 14.007, 15.9999, 18.99840316, 20.180,//Array for the atomic mass.
        22.9897693, 24.305, 26.981538, 28.085, 30.97376200, 32.07, 35.45, 39.9, 39.0983, 40.08,
        44.95591, 47.867, 50.9415, 51.996, 54.93804, 55.84, 58.933195, 58.693, 63.55, 65.4,
        69.723, 72.63, 74.92159, 78.97, 79.90, 83.80, 85.468, 87.62, 88.90584, 91.22,
        92.90637, 95.95, 96.90636, 101.1, 102.9055, 106.42, 107.868, 112.41, 114.818, 118.71,
        121.760, 127.6, 126.9045, 131.29, 132.9054520, 137.33, 138.9055, 140.116, 140.90766, 144.24,
        144.91276, 150.4, 151.964, 157.25, 158.92535, 162.500, 164.93033, 167.26, 168.93422, 173.05,
        174.9667, 178.49, 180.9479, 183.84, 186.207, 190.2, 192.22, 195.08, 196.96657, 200.59,
        204.3833, 207.0, 208.98040, 208.98243, 209.98715, 222.01758, 223.01973, 226.02541, 227.02775, 232.038,
        231.03588, 238.0289, 237.048172, 244.06420, 243.061380, 247.07035, 247.07031, 251.07959, 252.0830, 257.09511,
        258.09843, 259.10100, 266.120, 267.122, 268.126, 269.128, 270.133, 269.1336, 277.154, 282.166, 282.169,
        286.179, 286.182, 290.192, 290.196, 293.205, 294.211, 295.216}; 


    char chemical_group[118][50] = {
        "Nonmetal", "Noble Gas", "Alkali Metal", "Alkaline Earth Metal", "Metalloid",//Array for the chemical group.
        "Nonmetal", "Nonmetal", "Nonmetal", "Halogen", "Noble Gas",
        "Alkali Metal", "Alkaline Earth Metal", "Post-Transition Metal", "Metalloid", 
        "Nonmetal", "Nonmetal", "Halogen", "Noble Gas", "Alkali Metal",
        "Alkaline Earth Metal", "Transition Metal", "Transition Metal", 
        "Transition Metal", "Transition Metal", "Transition Metal",
        "Transition Metal", "Transition Metal", "Transition Metal",
        "Transition Metal", "Transition Metal", "Post-Transition Metal",
        "Metalloid", "Metalloid", "Nonmetal", "Halogen", "Noble Gas",
        "Alkali Metal", "Alkaline Earth Metal", "Transition Metal", 
        "Transition Metal", "Transition Metal", "Transition Metal", 
        "Transition Metal", "Transition Metal", "Transition Metal", 
        "Transition Metal", "Transition Metal", "Transition Metal", 
        "Post-Transition Metal", "Post-Transition Metal", "Metalloid", 
        "Metalloid", "Halogen", "Noble Gas", "Alkali Metal", 
        "Alkaline Earth Metal", "Lanthanide", "Lanthanide", "Lanthanide",
        "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide", 
        "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide", 
        "Lanthanide", "Lanthanide", "Lanthanide", "Lanthanide",
        "Transition Metal", "Transition Metal", "Transition Metal", 
        "Transition Metal", "Transition Metal", "Transition Metal", 
        "Transition Metal", "Transition Metal", "Transition Metal",
        "Post-Transition Metal", "Post-Transition Metal", "Post-Transition Metal", 
        "Metalloid", "Halogen", "Noble Gas", "Alkali Metal", 
        "Alkaline Earth Metal", "Actinide", "Actinide", "Actinide", "Actinide", 
        "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", 
        "Actinide", "Actinide", "Actinide", "Actinide", "Actinide", 
        "Actinide", "Transition Metal", "Transition Metal", 
        "Transition Metal", "Transition Metal", "Transition Metal", 
        "Transition Metal", "Transition Metal", "Transition Metal", 
        "Transition Metal", "Post-Transition Metal", "Post-Transition Metal",
        "Post-Transition Metal", "Post-Transition Metal", "Halogen", "Noble Gas" };

    char table[118][10]={"1:H", "2:He", "3:Li", "4:Be", "5:B", "6:C", "7:N", "8:O", "9:F", "10:Ne",//Array for the periodic table.
        "11:Na", "12:Mg", "13:Al", "14:Si", "15:P", "16:S", "17:Cl", "18:Ar", "19:K", "20:Ca",
        "21:Sc", "22:Ti", "23:V", "24:Cr", "25:Mn", "26:Fe", "27:Co", "28:Ni", "29:Cu", "30:Zn",
        "31:Ga", "32:Ge", "33:As", "34:Se", "35:Br", "36:Kr", "37:Rb", "38:Sr", "39:Y", "40:Zr",
        "41:Nb", "42:Mo", "43:Tc", "44:Ru", "45:Rh", "46:Pd", "47:Ag", "48:Cd", "49:In", "50:Sn",
        "51:Sb", "52:Te", "53:I", "54:Xe", "55:Cs", "56:Ba", "57:La", "58:Ce", "59:Pr", "60:Nd",
        "61:Pm", "62:Sm", "63:Eu", "64:Gd", "65:Tb", "66:Dy", "67:Ho", "68:Er", "69:Tm", "70:Yb",
        "71:Lu", "72:Hf", "73:Ta", "74:W", "75:Re", "76:Os", "77:Ir", "78:Pt", "79:Au", "80:Hg",
        "81:Tl", "82:Pb", "83:Bi", "84:Po", "85:At", "86:Rn", "87:Fr", "88:Ra", "89:Ac", "90:Th",
        "91:Pa", "92:U", "93:Np", "94:Pu", "95:Am", "96:Cm", "97:Bk", "98:Cf", "99:Es", "100:Fm",
        "101:Md", "102:No", "103:Lr", "104:Rf", "105:Db", "106:Sg", "107:Bh", "108:Hs", "109:Mt",
        "110:Ds", "111:Rg", "112:Cn", "113:Nh", "114:Fl", "115:Mc", "116:Lv", "117:Ts", "118:Og"};
    
    int starting_answer=0;//Answer that controls the choice of the user, if he wants to continue or not.
    do
    {
        int answerF1=0;  //Variable that we use to return the answer from the F1 function to main.
        starting_answer=F1(answerF1);  
        if (starting_answer==1) //Case, the user types 1.
        { 
            clearmonitor();// Clearing the monitor.
            int answerF2=0; //Variable that we use to return the answer from F2 function to main.
            F2(answerF2, name, symbol, chemical_group, atomic_mass,atomic_number);       
        }
        else if (starting_answer==2)
        {
            clearmonitor(); 
            int answerF4=0; //Variable that we use to return the answer from the F4 function to main.
            F4(answerF4,chemical_group,table,name,symbol,atomic_number,atomic_mass);
        }
    }while(starting_answer!=3);//If starting_answer is 3 it ends.
  
}

int linear_search(char item[118][50],int size, char item_choise[50]) //Linear search to find the given name or symbol.
{
    for (int i=0; i<size; i++)
    {
        if (strcmp(item[i], item_choise)==0)
            return i;// We did find the given item.
        
    }
    return -1; //We did not find the given item
}

int binary_search(int atomic_number[],int size,int atomic_n_choise) //Binary search to find the given atomic number.
{
    int left=0, right=size-1;

    while(left<=right)
    {
        int mid=left+(right-left)/2;
        
        if (atomic_number[mid]==atomic_n_choise)
        {
            return mid; //We found the atomic number.
        }
        if (atomic_number[mid]<atomic_n_choise)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return -1; //We did not find the atomic number.
}

void F3(int position,char name[118][50],char symbol[118][50],char chemical_group[118][50],double atomic_mass[118])//Third monitor.
{
    printf("   |----------------------------|\n");
    printf("   | Periodic Table of Elements |\n");
    printf("   |----------------------------|\n\n");
    printf("  Element description\n");
    printf("  1.Atomic Number: %d\n",position+1);
    printf("  2.Name: %s\n",name[position]);
    printf("  3.Symbol: %s\n",symbol[position]);
    printf("  4.Chemical Group: %s\n",chemical_group[position]);
    printf("  5.Atomic Mass: %lf\n\n",atomic_mass[position]);
}

void clearmonitor()
{
 system("clear"); //Clear the monitor.
}

int answer_scan_check(int answer)//Answer check for F1 & F2 function.
{
     //Asking the user to give us his answer and checking if its correct.
    do 
    {
        if ((scanf("%d", &answer) != 1) || (answer!=1 && answer!=2 && answer!=3))
        {
            printf("  This option does not exist! Type your selection (1,2 or 3): ");
            /*  Empty scanf buffer */
            while (getchar() != '\n');
        } 
        else 
        {
          break;
        }
    }while (1);
        return answer;
}

int F1(int answerF1) //First monitor.
{
    //Making the starting monitor.
    clearmonitor();
    printf("   |----------------------------|\n");
    printf("   | Periodic Table of Elements |\n");
    printf("   |----------------------------|\n\n");
    printf("  1. Search for individual elements\n");
    printf("  2. Search for group of elements\n");
    printf("  3. Terminate application\n\n");
    printf("  Type your selection (1,2 or 3): ");
    return answer_scan_check(answerF1); //Function that asks and checks if the answer given is correct.
}

int F2(int answerF2,char name[118][50],char symbol[118][50],char chemical_group[118][50],double atomic_mass[118],int atomic_number[118]) // Second monitor.
{
    int con_rest=1; //Variable that has the choise of the user if it is 1 he continiues to search for individual elements and if its is 0 it goes back    
    do
    {
        //Making the monitor.
        printf("   |----------------------------|\n");
        printf("   | Periodic Table of Elements |\n");
        printf("   |----------------------------|\n\n");
        printf("  Individual element search, based on:\n");
        printf("  1. Atomic Number\n");
        printf("  2. Name\n");
        printf("  3. Symbol\n\n");
        printf("  Type your selection (1,2 or 3): ");
    
        int choiseF2= answer_scan_check(answerF2); //Function that asks and checks if the answer given is correct.
    
        if (choiseF2==1) //If the user prefers to search for the element based on the atomic number.
        {
            printf("\n  Provide element atomic number: ");
            
            int atomic_n_choise;//Variable that holds the value that the user gave.
            int position1;//Variable that has the atomic number after the binary search.

            do //Scanning, Checking if the atomic number given exists.
            {
                if ((scanf("%d", &atomic_n_choise) != 1) || (position1=binary_search(atomic_number,118,atomic_n_choise))==-1)
                {
                    printf("  Error reading atomic number, try again: ");
                    /*  Empty scanf buffer */
                    while (getchar() != '\n');
                } 
                else 
                {
                    
                    break;
                }
            }while (1);//Returns 1 when the user gives a correct atomic number.
            clearmonitor();
            F3(position1,name,symbol,chemical_group,atomic_mass); //Functions that prints the answer for the element that the user wants to search.
        }
        else if (choiseF2==2) //If the user prefers to search for the element based on the name.
        {
            printf("\n  Provide element name: ");
            char name_choise[50];
            int position2; //Variable that contains the position that the element was found in the array.
            do
            {
                scanf("%s",name_choise);
                if ((position2=linear_search(name,118,name_choise))==-1)
                {
                    printf("  Error reading element name, Try again: ");
                    /*  Empty scanf buffer */
                    while (getchar() != '\n');
                }
                else
                {
                    break;
                }
            }while(1);
            clearmonitor();
            F3(position2,name,symbol,chemical_group,atomic_mass); //Functions that prints the answer for the element that the user wants to search.
        }
        else 
        {
            printf("\n  Provide element symbol: ");
            char symbol_choise[50];
            int position3; //Variable that contains the position that the element was found in the array.
            do
            {
                scanf("%19s",symbol_choise);
                if ((position3=linear_search(symbol,118,symbol_choise))==-1)
                {
                    printf("  Error reading element symbol, Try again: ");
                    /*  Empty scanf buffer */
                    while (getchar() != '\n');
                }
                else
                {
                    break;
                }
            }while(1);
            clearmonitor();
            F3(position3,name,symbol,chemical_group,atomic_mass); //Functions that prints the answer for the element that the user wants to search.
        }
        printf("  What yould you like to do next?\n  1. Continue searching for individual elements.\n  2. Go back to the beginning.\n  Type your selection:  ");//Checking if the user wants to continue searching for individual elements.
        do 
        {
            if ((scanf("%d",&con_rest)!=1) || (con_rest!=1 && con_rest!=2))
            {
                printf("This option does not exist! Type your selection (1 or 2): ");
                /*  Empty scanf buffer */
                while (getchar() != '\n');
            } 
            else 
            {
              break;
            }
        }while (1);
        clearmonitor();
    }while (con_rest==1);
    return 2;
}

int F5(int min_a_n,int max_a_n,char cg[50],float min_a_mass,float max_a_mass,char table[118][10],int atomic_number[118],char chemical_group[118][50],double atomic_mass[118])//Fifth monitor.
{
    int con_rest=1; //Variable that has the choise of the user if it is 1 he continiues to search for individual elements and if its is 0 it goes back  
        printf("                                                 |----------------------------|\n");
        printf("                                                 | Periodic Table of Elements |\n");
        printf("                                                 |----------------------------|\n\n");
        printf("  Selected group of elements:\n\n\n");
        
        int i=0;
        while (i<118)
        {  
            if (((min_a_n !=0) || (max_a_n!=0)) && ((min_a_mass !=0) || (max_a_mass !=0)) && !((strcmp(cg,"0"))==0))//If the user wants to search elements by their atomic number, their atomic mass and their chemical group.
            {
                if(((atomic_number[i]>=min_a_n)&&(atomic_number[i]<=max_a_n))&&((atomic_mass[i]>=min_a_mass)&&(atomic_mass[i]<=max_a_mass))&&(strcmp(cg,chemical_group[i])==0))
                    printf("\033[31m%7s\033[0m",table[i]);
                else if (((atomic_number[i]>=min_a_n)&&(max_a_n==0))&&((atomic_mass[i]>=min_a_mass)&&(max_a_mass==0))&&(strcmp(cg,chemical_group[i])==0))
                    printf("\033[31m%7s\033[0m",table[i]);   
                else if (((atomic_number[i]<=max_a_n)&&(min_a_n==0))&&((atomic_mass[i]<=max_a_mass)&&(min_a_mass==0))&&(strcmp(cg,chemical_group[i])==0))
                    printf("\033[31m%7s\033[0m",table[i]);
                else
                     printf("%7s",table[i]);   
                

                
            }
            else if (((min_a_n !=0) || (max_a_n !=0)) && !((strcmp(cg,"0")==0)))//If the user wants to search elements by their atomic number and their chemical group.
            {
                if (((atomic_number[i]>=min_a_n)&&(atomic_number[i]<=max_a_n))&&(strcmp(cg,chemical_group[i])==0))
                    printf("\033[31m%7s\033[0m",table[i]);
                else if (((atomic_number[i]>=min_a_n)&&(max_a_n==0))&&(strcmp(cg,chemical_group[i])==0))
                    printf("\033[31m%7s\033[0m",table[i]);   
                else if (((atomic_number[i]<=max_a_n)&&(min_a_n==0))&&(strcmp(cg,chemical_group[i])==0))
                    printf("\033[31m%7s\033[0m",table[i]);
                else 
                    printf("%7s",table[i]);
                
            }
            else if (((min_a_mass !=0) || (max_a_mass !=0)) && !((strcmp(cg,"0"))==0))  //If the user wants to search elements by their atomic mass and their chemical group.
            {
                if (((atomic_mass[i]>=min_a_mass)&&(atomic_mass[i]<=max_a_mass))&&(strcmp(cg,chemical_group[i])==0))
                    printf("\033[31m%7s\033[0m",table[i]);
                else if (((atomic_mass[i]>=min_a_mass)&&(max_a_mass==0))&&(strcmp(cg,chemical_group[i])==0))
                    printf("\033[31m%7s\033[0m",table[i]);   
                else if (((atomic_mass[i]<=max_a_mass)&&(min_a_mass==0))&&(strcmp(cg,chemical_group[i])==0))
                    printf("\033[31m%7s\033[0m",table[i]);
                else 
                    printf("%7s",table[i]);
                
            }
            else if (((min_a_n !=0) || (max_a_n!=0)) && ((min_a_mass !=0) || (max_a_mass !=0)))//If the user wants to search elements by their atomic number and their atomic mass.
            {
                if(((atomic_number[i]>=min_a_n)&&(atomic_number[i]<=max_a_n))&&((atomic_mass[i]>=min_a_mass)&&(atomic_mass[i]<=max_a_mass)))
                    printf("\033[31m%7s\033[0m",table[i]);
                else if (((atomic_number[i]>=min_a_n)&&(max_a_n==0))&&((atomic_mass[i]>=min_a_mass)&&(max_a_mass==0)))
                    printf("\033[31m%7s\033[0m",table[i]);   
                else if (((atomic_number[i]<=max_a_n)&&(min_a_n==0))&&((atomic_mass[i]<=max_a_mass)&&(min_a_mass==0)))
                    printf("\033[31m%7s\033[0m",table[i]);
                else 
                    printf("%7s",table[i]);
                
            }
            else if ((min_a_n !=0) || (max_a_n!=0)) //If the user wants to search elements by their atomic number.
            {
                if (atomic_number[i]>=min_a_n)
                {
                    if ((atomic_number[i]<=max_a_n)||(max_a_n==0))
                        printf("\033[31m%7s\033[0m",table[i]);
                    else
                        printf("%7s",table[i]);
                }
                else
                    printf("%7s",table[i]);
                
               
            }
            else if ((min_a_mass !=0) || (max_a_mass !=0)) //If the user wants to search elements by their atomic mass.+
            {
                if ((atomic_mass[i]>=min_a_mass))
                {
                    if ((atomic_mass[i]<=max_a_mass)||(max_a_mass==0))
                        printf("\033[31m%7s\033[0m",table[i]);
                    else
                        printf("%7s",table[i]);   
                }
                else 
                    printf("%7s",table[i]);
                
            }
            else if (!((strcmp(cg,"0"))==0))//If the user wants to search elements by their chemical group.
            {
                if (strcmp(cg,chemical_group[i])==0)
                    printf("\033[31m%7s\033[0m",table[i]);
                else 
                    printf("%7s",table[i]);
            }
            else
            {
                 printf("%7s",table[i]);   
            }

            //The periodic table has a predetermined way of printing, the following code explains it.
            if (i==0)
                printf("                                                                                                                ");
            if ((i==1) || (i==9)|| (i==17) || (i==35) || (i==53)|| (i==85))
                printf("\n");
            if (i==3)
                printf("                                                                      ");
            if (i==11)
                printf("                                                                      ");
            if (i==55)
            {
                printf("       ");
                i=71;
                continue;
            }
            if (i==87)
            {
                printf("       ");
                i=103;
                continue;
            }
            if (i==117)
            {
                printf("\n                     ");
                i=56;
                continue;
            }
            if (i==70)
            {
                printf("\n                     ");
                i=88;
                continue;
            }
            if (i==102)
                break;
            else
                i++;
        }
        printf("\n\n  What would you like to do next? \n  1. Continue searching for group of elements.\n  2. Go back to the beginning.\n  Type your selection:  "); //Checking if the user wants to continue searching for group of elements.
        do 
        {
            if ((scanf("%d",&con_rest)!=1) || (con_rest!=1 && con_rest!=2))
            {
                printf("  This option does not exist! Type your selection (1 or 2): ");
                /*  Empty scanf buffer */
                while (getchar() != '\n');
            } 
            else 
            {
            break;
            }
        }while (1);
        clearmonitor();
        if (con_rest==1)
            return 1;
        else
           return 2;
}

void F4(int answerF4,char chemical_group[118][50],char table[118][10],char name[118][50],char symbol[118][50],int atomic_number[118],double atomic_mass[118])//Fourth monitor.
{
    int con_rest=1;
    do
    {
       //Making the monitor.
        printf("   |----------------------------|\n");
        printf("   | Periodic Table of Elements |\n");
        printf("   |----------------------------|\n\n");
        printf("  Group of elements search, define criteria:\n");
        printf("  1. Minimum atomic number: ");
        
        
        int min_a_n;//Asking the user to give us his minimum atomic number.
        do 
        {
        if ((scanf("%d", &min_a_n) != 1) || ((min_a_n<0)||(min_a_n>118)))
        {
            printf("  This atomic number is incorrect! Please try again: ");
            /*  Empty scanf buffer */
            while (getchar() != '\n');
        } 
        else 
        {
          break;
        }
        }while (1);

        printf("  2. Maximum atomic number: ");
        int max_a_n; //Asking the user to give us his maximum atomic number.
        do 
        {
        if ((scanf("%d", &max_a_n) != 1) || ((max_a_n<0)||(max_a_n>118))||((max_a_n<min_a_n)&&(max_a_n != 0)))
        {
            printf("  This atomic number is incorrect! Please try again: ");
            /*  Empty scanf buffer */
            while (getchar() != '\n');
        } 
        else 
        {
          break;
        }
        }while (1);

        printf("  3. Chemical group block: ");
        char cg[50];
        do
        {
             while (getchar() != '\n');//Empty scanf buffer.
            fgets(cg,sizeof(cg),stdin);
            cg[strlen(cg)-1]='\0';//Making the last cell of the array \0
            if (cg[0]=='0')
            {
                break;
            }
            else if ((linear_search(chemical_group,118,cg))==-1)
            {
                printf("  Error reading Chemical group, Try again: ");
                /*  Empty scanf buffer */
                while (getchar() != '\n');
            }
            else
            {
                break;
            }
        }while(1);

        printf("  4. Minimum atomic mass: ");
        float min_a_mass; //Asking the user to give us his minimum atomic mass.
        do 
        {
        if ((scanf("%f", &min_a_mass) != 1) || ((min_a_mass<0)||(min_a_mass>295.216)))
        {
            printf("  This atomic number is incorrect! Please try again: ");
            /*  Empty scanf buffer */
            while (getchar() != '\n');
        } 
        else 
        {
          break;
        }
        }while (1);

        printf("  5. Maximum atomic mass:  ");
        float max_a_mass; //Asking the user to give us his maximum atomic mass.
        do 
        {
        if ((scanf("%f", &max_a_mass) != 1) || ((max_a_mass<0)||(max_a_mass>295.216))||((max_a_mass<min_a_mass)&&(max_a_mass != 0))) 
        {
            printf("  This atomic number is incorrect! Please try again: ");
            /*  Empty scanf buffer */
            while (getchar() != '\n');
        } 
        else 
        {
          break;
        }
        }while (1);

        clearmonitor();
        con_rest=F5(min_a_n,max_a_n,cg,min_a_mass,max_a_mass,table,atomic_number,chemical_group,atomic_mass);//Variable that contains the chois of the user if he wants to continue or not.
    }while(con_rest==1);
}





