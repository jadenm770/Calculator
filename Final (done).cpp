//Kazauni Forbes,   Clive Mahadeo,   Stefan Davis
//1903496           1901695          1707478
//Programming For Engineers : Final Project
//Number System

#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

//each line starting with 'cout' is an output statement.
//each line starting with 'cin' is an input statement.

int DToH(int deci ){

	int i = 1;
	int *hexaW = new int[0];
	int *hexaR = new int[0];

	hexaW[0] = deci / 16;
	hexaR[0] = deci % 16;
	int o = 0;

	while(1){

		hexaW[i] = hexaW[i-1]/ 16;
		hexaR[i] = hexaW[i-1]% 16;

		if(hexaW[i]==0){
			break;
		}
		i++;

	}
    char HexNum[i];

	for(int c=i; c>=0; c--){

		if(hexaR[c] >= 10 && hexaR[c] <=15){
			HexNum[o] = hexaR[c] + 55;
		}else if(hexaR[c] >=0 && hexaR[c]<=9){
				HexNum[o] = hexaR[c] + 48;
		}
		o++;
}       for(int u=0; u<=i; u++){
		cout<<HexNum[u];
}


}

int HToD(char Hexa[20]){
	int i;
	int full;
	int countH = 0;
	int temp;
	full = strlen(Hexa);
		for(i=0 ; Hexa[i] !='\0'; i++){
            full--;
			if(Hexa[i] >= '0' && Hexa[i]<= '9'){
                temp = (Hexa[i] - 48);
			}
			else if (Hexa[i] >= 'A' && Hexa[i] <= 'F'){
               temp = (Hexa[i] - 55);
			}
			countH += temp * pow(16,full);
		}

		return countH;
}

int DToO(int deci){
	int i = 1;
	int *OctW;
	OctW = new int[0];
	int *OctR;
	OctR = new int[0];
	int o = 0;


	OctW[0] = deci / 8;
	OctR[0] = deci % 8;

	while(1){
		OctW[i] = OctW[i-1] / 8;
		OctR[i] = OctW[i-1] % 8;
		if(OctW[i]== 0){
			break;
		}
		i++;
	}
	char OctNum[o];
	for(int c=i; c>=0; c--){

		if(OctR[c] >=0 && OctR[c]<=9){
				OctNum[o] = OctR[c] + 48;
		}
		o++;
}
	cout<<OctNum;

}

int OToD(char Oct[20]){
	int counter;
	counter = strlen(Oct);
	int temp;
	int total = 0;

	for(int i=0; Oct[i]!='\0'; i++){
		counter--;
		temp = Oct[i] - 48;
		total+= temp * pow(8,counter);
	}

	return total;

}

int dtb(int d);//decimal to binary function, enter decimal
int dtb(int d)
{
    int DB[100]; int c = 1; int cc,j; //variable declarations

    while (d != 0) //once decimal is not zero
    {
        j=(c++); //counter and pointer
        DB[j] = (d % 2); //array to hold each character of the binary number
        d = (d/2); //changes the value of the decimal
    }

    for (cc = (c-1); cc > 0 ; cc--) //loop for printing
    {
        cout<<DB[cc]; //each character of the binary number
    }
}
int btd(int bin); //binary to decimal function, enter binary number
int btd(int bin)
{
    int DB[100]; int c = 1; int rem; int k = 0; int sum = 0;

    while (bin > 0) //while binary number is greater than zero
    {
        rem = bin % 10; //holds remainder after the number is divided by 10
        if (rem == 0 || rem == 1) //once the remainder is 1 or 0
        {
            sum = sum + rem * pow(2,k); //changes the value of sum which will be the decimal number
        }
        else
        {
            c = 0; //holding value shows that the loop was ended
            break; //ends the loop
        }
        k++; //counts each time the loop runs
        bin = bin/10; //changes the value of bin
    }

    if (c) //if the holding value showing the loop ended was used
    {
        return sum; //decimal number
    }
    else //holding value was not used
    {
        cout<<"\nInvalid"; //error message
    }
}

long dtbcd(string d); //decimal to binary coded decimal function, enter decimal number of string type
long dtbcd(string d)
{
    int sz = d.length(); //counter which is the length of the string/number

    for (int c=0; c<sz ; c++) //loop for checking each character of the decimal number
    {
        char temp = d.at(c); //assign character in string to variable
        //check each value and deals with it accordingly
        if(temp == '0'){cout<<"0000";} if(temp == '1'){cout<<"0001";} if(temp == '2'){cout<<"0010";}
        if(temp == '3'){cout<<"0011";} if(temp == '4'){cout<<"0100";} if(temp == '5'){cout<<"0101";}
        if(temp == '6'){cout<<"0110";} if(temp == '7'){cout<<"0111";} if(temp == '8'){cout<<"1000";}
        if(temp == '9'){cout<<"1001";} else{cout<<" ";}
    }
}
int bcdtd(string Bcd); //binary coded decimal to decimal function
int bcdtd(string Bcd)
{
    string BCD[50]; //string array to hold words
    int co = -1; //counter/pointer declaration
    istringstream Word(Bcd); //string stream declaration to hold words

    do
    {
        co = co+1; //counter/pointer value assignment
        string w; //string to hold word/bcd
        Word >> w; //assign word/bcd to string
        BCD[co] = w; //assign string to space in array

    } while(Word); //assignments once a word/bcd is scanned

    int BCDD[co]; //array to hold numbers
    int err = 1; //error detector variable

    for(int g=0 ; g<co ; g++) //loop to scan each word/bcd and deal with them accordingly
    {
        if(BCD[g] == "0000"){BCDD[g]=0; err=0;} if(BCD[g] == "0001"){BCDD[g]=1; err=0;} if(BCD[g] == "0010"){BCDD[g]=2; err=0;}
        if(BCD[g] == "0011"){BCDD[g]=3; err=0;} if(BCD[g] == "0100"){BCDD[g]=4; err=0;} if(BCD[g] == "0101"){BCDD[g]=5; err=0;}
        if(BCD[g] == "0110"){BCDD[g]=6; err=0;} if(BCD[g] == "0111"){BCDD[g]=7; err=0;} if(BCD[g] == "1000"){BCDD[g]=8; err=0;}
        if(BCD[g] == "1001"){BCDD[g]=9; err=0;} if(err == 1){cout<<"\nError";}
    }
    int D[co]; //array to hold decimal numbers
    int cg = co-1; //counter maximum
    int cgg = 0; //counter/pointer for array
    for(int gg=cg ; gg>=0 ; gg--) //loop to multiply the number by a power of 10
    {
        int dh = BCDD[cgg]; //holder for array value
        D[gg] = (dh * (pow(10,gg))); //assignment of each value in the decimal array
        cgg = cgg + 1; //counter/pointer value change
    }
    int dnum=0; //decimal value holder
    int d; //array point value holder
    for(int ggg=0 ; ggg<co ; ggg++) //loop to create the decimal number
    {
        d = D[ggg]; //assign array value to variable
        dnum = dnum + d; //add each array number
    }
    return dnum; //final decimal number
}
long check6(long o6); //function to ensure a number from 1 to 6 is selected, enter the number
long check6(long o6)
{
    while (o6 < 1 || o6 > 6) //check if the number exceeds 1 or 6
    {
        cout<<"\nERROR, enter the corresponding number : ";
        cin>>o6;
    }
    return o6; //returns the number once the condition is met
}
long opt6(long o); //function to select number system
long opt6(long o)
{
    cout<<"\n\nPlease enter the NUMBER that corresponds to your choice from the list: ";
    cout<<"\nWhich system is the number(s) from :";
    cout<<"\n\n1) Binary        |   2) Binary-coded Decimal   |   3) Octal";
    cout<<"\n4) Hexadecimal   |   5) Decimal                |   6) Return to main menu\n";
    cout<<"\n- From : ";
    cin>>o;
    o=check6(o); //checks the input by calling the check6 function

    return o; //returns the choice
}

long opt2(long yn); //yes/no function.
long opt2(long yn)
{
    cout<<"\nState the number of your choice; 1) Yes, 2) No : ";
    cin>>yn; //main menu loop parameter assignment.

    while ((yn < 1) || (yn > 2)) //Loop for inadequate entry.
    {
        cout<<"\nERROR, enter the corresponding number; 1)yes, 2)no : ";
        cin>>yn;
    }
    return yn; //returns adequate result
}

long redo(long re); //function for restart of specific operation.
long redo(long re)
{
    cout<<"\nDo you want to do another calculation?\n";
    re= opt2(re); //yes/no function call.
    return re;
}

long Menu(long mm); //function for main menu return.
long Menu(long mm)
{
    cout<<"\nDo you want to return to the main menu?";
    mm= opt2(mm); //yes/no function call.
    return mm;
}

long restartb; //variable to hold value for restart of specific operations
float hold; //holding value
long S,F,r,P,C,menu,option,option2,option3,hold2; //declaration of some variables.
int main()

{
    system("Color E0");  // first E = yellow background, second 0 = black text.
    menu = 1; //holding value for start of main menu loop.
    while (menu==1) //main menu loop.
    {
    cout<<"___________________________________________________________________________";
    cout<<"\n========================= M A I N  ======  M E N U ========================";
    cout<<"\n___________________________________________________________________________";
    cout<<"\nThis program will compute the number(s) you enter to \nbased on five number systems.";
    cout<<"\n___________________________________________________________________________";

    cout<<"\n\nThis program can carry out the following operations.\n";
    cout<<"\n1) Addition    |    2) Subtraction    |    3) Multiplication";
    cout<<"\n4) Division    |    5) Conversion     |    6) Exit";
    cout<<"\n\nPlease enter the number that corresponds with \nthe operation you wish to carry out : ";
    cin>>option;
    while (option < 1 || option > 6) //Loop for inadequate entry.
    {
        cout<<"\nERROR, enter the corresponding number : ";
        cin>>option;
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (option==1) //ADDITION----------------------------
    {
        restartb=1; //holding value to start the loop
        while (restartb == 1) //looping condition
        {
        cout<<"\n\n____________________________A D D I T I O N________________________________";//++++++++++++++++++++++++++++++++++++++++++++++++
        cout<<"\n___________________________________________________________________________";
        option2=opt6(hold2); //User input

        if (option2==6){cout<<"\n\n"; break;} //ends the loop if user selects return to main menu

        if (option2 == 1) //Binary addition-------------------------------------------------------------------------------
            {
                long restartc=1; //holding value to start the loop
                while (restartc==1) //looping condition
                {
                int badd1,badd2,ad1,ad2,sum,bsum; //variable declaration
                cout<<"\n--------------------BINARY ADDITION--------------------";
                cout<<"\nPlease enter the first binary number : ";
                cin>>badd1;
                cout<<"\nPlease enter the second binary number : ";
                cin>>badd2;

                ad1=btd(badd1); //convert binary to decimal
                ad2=btd(badd2); //convert binary to decimal
                sum =(ad1 + ad2); //decimal addition

                cout<<"\n\n"<<badd1<<" + "<<badd2<<" = ";
                dtb(sum); //sum conversion to binary

                cout<<"\n\n- Do you want to do another binary addition?";
                restartc=opt2(restartc); //loop condition assignment
                }
            }

        if (option2 == 2) //Binary Coded Decimal addition-------------------------------------------------------------------
        {
            long restartc=1; //holding value to start the loop
            while (restartc==1) //loop condition
            {
                string badd1,badd2; //variable declaration
                int ad1,ad2,sum,bsum;
                cout<<"\n--------------BINARY CODED DECIMAL ADDITION--------------";
                cout<<"\nPlease enter the first binary coded decimal number : ";
                getline(cin,badd1);
                getline(cin,badd1);
                cout<<"\nPlease enter the second binary coded decimal number : ";
                getline(cin,badd2);

                ad1=bcdtd(badd1); //convert bcd to decimal
                ad2=bcdtd(badd2); //convert bcd to decimal
                sum =(ad1 + ad2); //decimal addition

                stringstream ssum; //string stream declaration for conversion
                ssum<<sum; //assign the decimal to a string stream
                string Sum; //string declaration
                ssum>>Sum; //assign contents of string stream to string

                cout<<"\n\n"<<badd1<<" + "<<badd2<<" = ";
                dtbcd(Sum); //decimal to bcd conversion

                cout<<"\n\n- Do you want to do another binary coded decimal addition?";
                restartc=opt2(restartc); //loop condition assignment
            }
        }

        if (option2 == 3) //Octal addition-------------------------------------------------------------------------------
        {
            long restartc=1; //holding value to start the loop
            while (restartc==1) //loop condition
            {
                char Oct1[20];
                int v1;
                int v2;
                int sum;
                cout<<"\n--------------OCTAL ADDITION--------------";
                cout<<"\nPlease enter the first octal number : ";
                cin>>Oct1;
                v1= OToD(Oct1);
                cout<<"\nPlease enter the second octal number : ";
                cin>>Oct1;
                v2= OToD(Oct1);
                sum = v1 + v2;
                cout<<"\nThe sum is ";
                DToO(sum);

                cout<<"\n\n- Do you want to do another octal addition?";
                restartc=opt2(restartc); //loop condition assignment
            }
        }

        if (option2 == 4) //HexaDecimal addition-------------------------------------------------------------------------------
        {
            long restartc=1; //holding value to start the loop
            while (restartc==1) //loop condition
            {
                char Hexa1[20];
                int y1,y2;
                int sum;
               cout<<"\n--------------HEXADECIMAL ADDITION--------------";
                cout<<"\nPlease enter the first hexadecimal number : ";
                cin>>Hexa1;
                y1= HToD(Hexa1);
                cout<<"\nPlease enter the second hexadecimal number : ";
                cin>>Hexa1;
                y2= HToD(Hexa1);
                sum = y1 + y2;
                cout<<"\nThe sum is ";
                DToH(sum);

                cout<<"\n\n- Do you want to do another Hexadecimal addition?";
                restartc=opt2(restartc); //loop condition assignment
            }
        }

        if (option2 == 5) //Decimal addition-------------------------------------------------------------------------------
        {
            long restartc=1; //holding value to start the loop
            while (restartc==1)
            {
                int badd1,badd2,ad1,ad2,sum; //variable declaration
                cout<<"\n--------------------DECIMAL ADDITION--------------------";
                cout<<"\nPlease enter the first decimal number : ";
                cin>>badd1;
                cout<<"\nPlease enter the second decimal number : ";
                cin>>badd2;

                sum =(badd1 + badd2); //decimal addition

                cout<<"\n\n"<<badd1<<" + "<<badd2<<" = "<<sum;

                cout<<"\n\n- Do you want to do another Decimal addition?";
                restartc=opt2(restartc); //loop condition assignment
            }
        }

        cout<<"\n- Do you want to Add any other type of number?";
        restartb=opt2(hold2); //loop condition assignment
        }
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (option==2) //SUBSTRACTION----------------------------
    {

        restartb=1; //holding value to start loop
        while (restartb == 1) //loop condition
        {
        cout<<"\n\n________________________S U B T R A C T I O N____________________________";//++++++++++++++++++++++++++++++++++++++++++++++++
        cout<<"\n___________________________________________________________________________";
        cout<<"\n\n- What kind of numbers do you want to subtract?";
        option2=opt6(hold2); //User input

        if (option2==6){cout<<"\n\n"; break;} //end loop if user selects return to menu

        if (option2 == 1) //Binary subtraction-------------------------------------------------------------------------------
            {
                long restartc=1; //holding value to start the loop
                while (restartc==1) //loop condition
                {
                int bsub1,bsub2,sb1,sb2,dif,bdif; //variable declaration
                cout<<"\n-------------------BINARY SUBTRACTION-----------------";
                cout<<"\nNOTE: This program does not support negative numbers.";
                cout<<"\nPlease enter the first binary number : ";
                cin>>bsub1;
                cout<<"\nPlease enter the binary number to be subtracted : ";
                cin>>bsub2;

                sb1=btd(bsub1); //binary to decimal conversion
                sb2=btd(bsub2); //binary to decimal conversion
                dif =(sb1 - sb2); //decimal subtraction

                if (dif>=0) //result must be greater than zero
                {
                    cout<<"\n\n"<<bsub1<<" - "<<bsub2<<" = ";
                    dtb(dif); //decimal to binary conversion
                }
                else{cout<<"\nNegative number.";}

                cout<<"\n\n- Do you want to do another binary subtraction?";
                restartc=opt2(restartc); //loop condition assignment
                }
            }

        if (option2 == 2) //Binary Coded Decimal subtraction-------------------------------------------------------------------------------
        {
            long restartc=1; //holding value to start the loop
            while (restartc==1) //loop condition
            {
                string bsub1,bsub2; //variable declarations
                int sb1,sb2,dif,bdif;
                cout<<"\n-------------BINARY CODED DECIMAL SUBTRACTION-------------";
                cout<<"\nPlease enter the first binary coded decimal number : ";
                getline(cin,bsub1);
                getline(cin,bsub1);
                cout<<"\nEnter the binary coded decimal number to be subtracted: ";
                getline(cin,bsub2);

                sb1=bcdtd(bsub1); //bcd to decimal conversion
                sb2=bcdtd(bsub2); //bcd to decimal conversion
                dif =(sb1 - sb2); // decimal subtraction

                if (dif>0) //result must be more than zero
                {
                stringstream ddif; //declaration of string stream for conversion
                ddif<<dif; //assign decimal contents to string stream
                string Dif; //string declaration
                ddif>>Dif; //assign contents of string stream to string variable

                cout<<"\n\n"<<bsub1<<" - "<<bsub2<<" = ";
                dtbcd(Dif); //decimal to bcd conversion of result
                }
                else{cout<<"\nNegative Number";} //result less than zero

                cout<<"\n\n- Do you want to do another binary coded decimal subtraction?";
                restartc=opt2(restartc); //loop condition assignment
            }
        }

        if (option2 == 3) //Octal subtraction-------------------------------------------------------------------------------
        {
            long restartc=1; //holding value to start the loop
            while (restartc==1)
            {
                char Oct1[20];
                int v1, v2, diff;
                cout<<"\n-------------------OCTAL SUBTRACTION-----------------";
                cout<<"\n--------------OCTAL ADDITION--------------";
                cout<<"\nPlease enter the first octal number : ";
                cin>>Oct1;
                v1= OToD(Oct1);
                cout<<"\nPlease enter the second octal number : ";
                cin>>Oct1;
                v2= OToD(Oct1);
                diff = v1 - v2;
                cout<<"\nThe sum is ";
                DToO(diff);
                //.....................

                cout<<"\n\n- Do you want to do another octal subtraction?";
                restartc=opt2(restartc); //loop condition assignment
            }
        }

        if (option2 == 4) //HexaDecimal subtraction-------------------------------------------------------------------------------
        {
            long restartc=1; //holding value to start the loop
            while (restartc==1)
            {
                char Hexa1[20];
                int v1,v2, diff;
                cout<<"\n----------------HEXADECIMAL SUBTRACTION---------------";
                //.....................

                cout<<"\n\n- Do you want to do another Hexadecimal subtraction?";
                cout<<"\n--------------HEXADECIMAL ADDITION--------------";
                cout<<"\nPlease enter the first hexadecimal number : ";
                cin>>Hexa1;
                v1= HToD(Hexa1);
                cout<<"\nPlease enter the second hexadecimal number : ";
                cin>>Hexa1;
                v2= HToD(Hexa1);
                diff = v1 - v2;
                cout<<"\nThe sum is ";
                DToH(diff);
                restartc=opt2(restartc); //loop condition assignment
            }
        }

        if (option2 == 5) //Decimal subtraction-------------------------------------------------------------------------------
        {
            long restartc=1; //holding value to start the loop
            while (restartc==1) //loop condition
            {
                int bsub1,bsub2,sb1,sb2,dif; //variable declaration
                cout<<"\n------------------DECIMAL SUBTRACTION------------------";
                cout<<"\nPlease enter the first decimal number : ";
                cin>>bsub1;
                cout<<"\nPlease enter the decimal number to be subtracted : ";
                cin>>bsub2;

                dif =(bsub1 - bsub2); //decimal subtraction

                cout<<"\n\n"<<bsub1<<" - "<<bsub2<<" = "<<dif;

                cout<<"\n\n- Do you want to do another Decimal subtraction?";
                restartc=opt2(restartc); //loop condition assignment
            }
        }

        cout<<"\n- Do you want to subtract any other type of number?";
        restartb=opt2(hold2); //loop condition assignment
        }
    }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (option==3) //MULTIPLICATION--------------------------
    {

        restartb=1; //holding value to start the loop
        while (restartb == 1) //loop condition
        {
        cout<<"\n\n_____________________M U L T I P L I C A T I O N_________________________";//++++++++++++++++++++++++++++++++++++++++++++++++
        cout<<"\n___________________________________________________________________________";
        cout<<"\n\n- What kind of numbers do you want to multiply?";
        option2=opt6(hold2); //User input

        if (option2==6){cout<<"\n\n"; break;} //end loop if user selects return to menu

        if (option2 == 1) //Binary multiplication-------------------------------------------------------------------------------
            {
                long restartc=1; //holding value to start the loop
                while (restartc==1) //loop condition
                {
                int bmul1,bmul2,m1,m2,mull,bmull; //variable declaration
                cout<<"\n-----------------BINARY MULTIPLICATION---------------";
                cout<<"\nNOTE: This program does not support negative numbers.";
                cout<<"\nPlease enter the first binary number : ";
                cin>>bmul1;
                cout<<"\nPlease enter the second binary number : ";
                cin>>bmul2;

                m1=btd(bmul1); //binary to decimal conversion
                m2=btd(bmul2); //binary to decimal conversion


                if ((m1>=0)&&(m2>=0)) //once both values are not negative
                {
                    mull =(m1 * m2); //decimal multiplication
                    cout<<"\n\n"<<bmul1<<" x "<<bmul2<<" = ";
                    dtb(mull); //decimal to binary conversion of result
                }
                else{cout<<"\nNegative number entered.";} //a negative nuber was entered

                cout<<"\n\n- Do you want to do another binary multiplication?";
                restartc=opt2(restartc); //loop condition assignment
                }
            }

        if (option2 == 2) //Binary Coded Decimal multiplication-------------------------------------------------------------------------------
        {
            long restartc=1; //holding value to start the loop
            while (restartc==1) //loop condition
            {
                string bmul1,bmul2; //variable declarations
                int m1,m2,mull,bmull;
                cout<<"\n----------BINARY CODED DECIMAL MULTIPLICATION-----------";
                cout<<"\nPlease enter the first binary coded decimal number : ";
                getline(cin,bmul1);
                getline(cin,bmul1);
                cout<<"\nEnter the binary coded decimal number to be multiplied: ";
                getline(cin,bmul2);

                m1=bcdtd(bmul1); //bcd to decimal conversion
                m2=bcdtd(bmul2); //bcd to decimal conversion
                mull =(m1 * m2); //decimal multiplication

                if ((m1>=0)&&(m2>=0)) //values must not be negative
                {
                stringstream mmul; //string stream declaration for conversion
                mmul<<mull; //assign variable contents to string stream variable
                string Mul; //string declaration
                mmul>>Mul; //assign string stream contents to string variable

                cout<<"\n\n"<<bmul1<<" x "<<bmul2<<" = ";
                dtbcd(Mul); //decimal to bcd conversion of result
                }
                else{cout<<"\nNegative number entered.";}

                cout<<"\n\n- Do you want to do another binary coded decimal multiplication?";
                restartc=opt2(restartc); //loop condition assignment
            }
        }

        if (option2 == 3) //Octal multiplication-------------------------------------------------------------------------------
        {
            long restartc=1; //holding value to start the loop
            while (restartc==1) //loop condition assignment
            {
                char Oct1[20];
                int v1, v2, product;
                cout<<"\n-----------------OCTAL MULTIPLICATION---------------";
                cout<<"\nPlease enter the first octal number : ";
                cin>>Oct1;
                v1= OToD(Oct1);
                cout<<"\nPlease enter the second octal number : ";
                cin>>Oct1;
                v2= OToD(Oct1);
                product = v1 * v2;
                cout<<"\nThe product is ";
                DToO(product);

                cout<<"\n\n- Do you want to do another octal multiplication?";
                restartc=opt2(restartc); //loop condition assignment
            }
        }

        if (option2 == 4) //HexaDecimal multiplication-------------------------------------------------------------------------------
        {
            long restartc=1; //holding value to start the loop
            while (restartc==1)
            {
                char Hex1[20];
                int v1, v2, product;
                cout<<"\n----------------HEXADECIMAL MULTIPLICATION---------------";

                cout<<"\nPlease enter the hexadecimal octal number : ";
                cin>>Hex1;
                v1= HToD(Hex1);
                cout<<"\nPlease enter the hexadecimal octal number : ";
                cin>>Hex1;
                v2= HToD(Hex1);
                product = v1 * v2;
                cout<<"\nThe product is ";
                DToO(product);

                cout<<"\n\n- Do you want to do another Hexadecimal multiplication?";
                restartc=opt2(restartc); //loop condition assignment
            }
        }

        if (option2 == 5) //Decimal multiplication-------------------------------------------------------------------------------
        {
            long restartc=1; //holding value to start the loop
            while (restartc==1) //loop condition
            {
                int bmul1,bmul2,m1,m2,mull;
                cout<<"\n----------------DECIMAL MULTIPLICATION----------------";
                cout<<"\nPlease enter the first decimal number : ";
                cin>>bmul1;
                cout<<"\nPlease enter the decimal number to be multiplied : ";
                cin>>bmul2;

                mull =(bmul1 * bmul2); //decimal multiplication

                cout<<"\n\n"<<bmul1<<" x "<<bmul2<<" = "<<mull;

                cout<<"\n\n- Do you want to do another Decimal multiplication?";
                restartc=opt2(restartc); //loop condition assignment
            }
        }

        cout<<"\n- Do you want to multiply any other type of number?";
        restartb=opt2(hold2); //loop condition assignment
        }
    }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (option==4) //DIVISION----------------------------------------
    {
        restartb=1; //holding value to start the loop
        while (restartb == 1) //loop condition assignment
        {
        cout<<"\n\n___________________________D I V I S I O N_______________________________";//++++++++++++++++++++++++++++++++++++++++++++++++
        cout<<"\n___________________________________________________________________________";
        cout<<"\n\n- What kind of numbers do you want to divide?";
        option2=opt6(hold2); //User input

        if (option2==6){cout<<"\n\n"; break;} //end loop if user selects return to menu

        if (option2 == 1) //Binary division-------------------------------------------------------------------------------
            {
                long restartc=1; //holding value to start the loop
                while (restartc==1) //loop condition assignment
                {
                int bdiv1,bdiv2,d1,d2,divv,bdivv; //variable declaration
                cout<<"\n-------------------BINARY DIVISION-------------------";
                cout<<"\nNOTE: This program does not support negative numbers.";
                cout<<"\n\nPlease enter the binary number to be divided : ";
                cin>>bdiv1;
                cout<<"\nPlease enter the second binary number (divider) : ";
                cin>>bdiv2;

                d1=btd(bdiv1); //binary to decimal conversion
                d2=btd(bdiv2);//binary to decimal conversion


                if ((d1>0)&&(d2>0)) //both must be greater than zero
                {
                    divv =(d1 / d2); //decimal division
                    cout<<"\n\n"<<bdiv1<<" / "<<bdiv2<<" = ";
                    dtb(divv); //decimal to binary conversion
                }
                else{cout<<"\nNegative number entered.";}

                cout<<"\n\n- Do you want to do another binary division?";
                restartc=opt2(restartc); //loop condition assignment
                }
            }

        if (option2 == 2) //Binary Coded Decimal division-------------------------------------------------------------------------------
        {
            long restartc=1; //holding value to start the loop
            while (restartc==1) //loop condition
            {
                string bdiv1,bdiv2; //variable declarations
                int d1,d2,divv,bdivv;
                cout<<"\n-------------BINARY CODED DECIMAL DIVISION-------------";
                cout<<"\nNOTE: This program does not support negative numbers.";
                cout<<"\n\nPlease enter the binary number to be divided : ";
                getline(cin,bdiv1);
                getline(cin,bdiv1);
                cout<<"\nPlease enter the second binary number (divider) : ";
                getline(cin,bdiv2);

                d1=bcdtd(bdiv1); //bcd to decimal conversion
                d2=bcdtd(bdiv2); //bcd to decimal conversion


                if ((d1>0)&&(d2>0)) //both must be greater than zero
                {
                    divv =(d1 / d2); //decimal division
                    stringstream ddiv; //string stream declaration for conversion
                    ddiv<<divv; //assign contents of variable to string stream
                    string Div; //string declaration
                    ddiv>>Div; //assign contents of string stream to string variable

                    cout<<"\n\n"<<bdiv1<<" / "<<bdiv2<<" = ";
                    dtbcd(Div); //decimal to bcd conversion
                }
                else{cout<<"\nInvalid input or undefined";}

                cout<<"\n\n- Do you want to do another binary coded decimal division?";
                restartc=opt2(restartc); //loop condition assignment
            }
        }

        if (option2 == 3) //Octal division-------------------------------------------------------------------------------
        {
            long restartc=1; //holding value to start the loop
            while (restartc==1)
            {
                char Oct1[20];
                int v1, v2, ans;
                cout<<"\n------------------OCTAL DIVISION-----------------";
                cout<<"\nPlease enter the first octal number : ";
                cin>>Oct1;
                v1= OToD(Oct1);
                cout<<"\nPlease enter the second octal number : ";
                cin>>Oct1;
                v2= OToD(Oct1);
                ans = v1 / v2;
                cout<<"\nThe sum is ";
                DToO(ans);
                //.....................

                cout<<"\n\n- Do you want to do another octal division?";
                restartc=opt2(restartc); //loop condition assignment
            }
        }

        if (option2 == 4) //HexaDecimal division-------------------------------------------------------------------------------
        {
            long restartc=1; //holding value to start the loop
            while (restartc==1)
            {
                char Hex1[20];
                int v1, v2, ans;
                cout<<"\n-----------------HEXADECIMAL DIVISION-----------------";

                cout<<"\nPlease enter the first hexadecimal number : ";
                cin>>Hex1;
                v1= HToD(Hex1);
                cout<<"\nPlease enter the second hexadecimal number : ";
                cin>>Hex1;
                v2= HToD(Hex1);
                ans = v1 / v2;
                cout<<"\nThe sum is ";
                DToH(ans);
                //.....................

                cout<<"\n\n- Do you want to do another Hexadecimal division?";
                restartc=opt2(restartc); //loop condition assignment
            }
        }

        if (option2 == 5) //Decimal division-------------------------------------------------------------------------------
        {
            long restartc=1; //holding value to start the loop
            while (restartc==1) //loop condition
            {
                int bdiv1,bdiv2,d1,d2,divv; //variable declaration
                cout<<"\n-------------------DECIMAL DIVISION------------------";
                cout<<"\nNOTE: This program does not support negative numbers.";
                cout<<"\n\nPlease enter the binary number to be divided : ";
                cin>>bdiv1;
                cout<<"\nPlease enter the second binary number (divider) : ";
                cin>>bdiv2;

                divv =(bdiv1 / bdiv2); //decimal division

                if ((bdiv1>0)&&(bdiv2>0))
                cout<<"\n\n"<<bdiv1<<" / "<<bdiv2<<" = "<<divv;

                cout<<"\n\n- Do you want to do another Decimal division?";
                restartc=opt2(restartc); //loop condition assignment
            }
        }

        cout<<"\n- Do you want to divide any other type of number?";
        restartb=opt2(hold2); //loop condition assignment
        }
    }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (option==5) //CONVERSON-------------------------------------------
    {
        restartb=1; //holding value for start of loop.
        while (restartb==1) //loop for Restart of specific program.
        {
            cout<<"\n\n____________________________C O N V E R S I O N____________________________";//++++++++++++++++++++++++++++++++++++++++++++++++
            cout<<"\n___________________________________________________________________________";
            cout<<"\n\n- Please choose the corresponding number of the systems you want to convert FROM and TO";
            option2=opt6(hold2); //User input

            if (option2 == 1) //Binary conversion-------------------------------------------------------------------------------
            {
                cout<<"\n- To : ";
                cin>>option3;

                while (option3==1)//binary to binary selected>>>>>>>>>>>>>>>>>>>>>>
                {
                    cout<<"\nYour number is already a binary. \nPlease choose another : ";
                    cin>>option3;
                    if ((option3 < 1) || (option3 > 6)){option3 = 1;} //loop for redundant choice
                }

                if (option3==2) //binary to binary coded decimal selected>>>>>>>>>>>>>>>>>
                {
                    int b,bd; //variable declaration
                    cout<<"\n-------BINARY TO BINARY CODED DECIMAL CONVERSION------";
                    cout<<"\nNOTE: This program uses the 4bit '8421' type of BCD encoding";
                    cout<<"\n\nPlease enter the binary number to be converted : ";
                    cin>>bd;

                    bd = btd(bd); //binary to decimal function call

                    stringstream BD; //string stream declaration for conversion
                    BD<<bd; //assign contents of variable to string stream
                    string Bd; //string declaration
                    BD>>Bd; //assign contents of string stream to string variable

                    cout<<"\nThe binary coded decimal equivalent : ";

                    dtbcd(Bd); //decimal to binary conversion

                }

                if (option3==3) //binary to Octal selected>>>>>>>>>>>>>>>
                {
                    int b, deci, oct;
                    cout<<"\n--------------BINARY TO OCTAL CONVERSION-------------";
                    cout<<"\nEnter the binary number : ";
                    cin>>b;
                    deci=btd(b); //decimal to octal conversion
                    cout<<deci;
                    cout<<"\n\nThe Octal equivalent : ";
                    oct=DToO(deci); //decimal to octal conversion
                }

                if (option3==4) //binary to Hexadecimal selected>>>>>>>>>>>>>>>
                {
                    int b, deci, hex;
                    cout<<"\n--------------BINARY TO HEXADECIMAL CONVERSION-------------";
                    cout<<"\nEnter the binary number : ";
                    cin>>b;
                    deci=btd(b); //binary to decimal conversion
                    cout<<deci;
                    cout<<"\n\nThe Hexadecimal equivalent : ";
                    hex=DToH(deci); //hexadecimal to binary conversion

                }

                if (option3==5) //Binary to decimal selected>>>>>>>>>>>>>>>>>>>
                {
                    int b,deci; //variable declaration
                    cout<<"\n--------------BINARY TO DECIMAL CONVERSION-------------";
                    cout<<"\nEnter the binary number : ";
                    cin>>b;
                    deci=btd(b); //binary to decimal function call.
                    cout<<"\n\nThe Decimal equivalent : "<<deci;
                }

                cout<<"\n\nDo you want to do another conversion?";
                restartb=opt2(restartb); //loop condition assignment
            }

            //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
            if (option2==2) //Binary Coded decimal conversion----------------------------------------------------------------
            {
                cout<<"\n- To : ";
                cin>>option3;
                option3=check6(option3); //checking function call to check input

                cout<<"\nNOTE : This program uses the 4-bit '8421' encoding where each decimal number is represented individually.";
                cout<<"\nThe key for this system is: ";
                cout<<"\n\n0= 0000 | 1= 0001 | 2= 0010 | 3= 0011 | 4= 0100 | 5= 0101 | 6= 0110 | 7= 0111 | 8= 1000 | 9= 1001";
                cout<<"\n\nSo '11' would be '0001 0001'";

                if (option3==1) //binary coded decimal to binary selected>>>>>>>>>>>>>>>
                {
                    int bcdd; //variable declarations
                    string bcd;
                    cout<<"\n\n---------BINARY CODED DECIMAL TO BINARY CONVERSION---------";

                    cout<<"\nEnter the binary coded decimal number to be converted : ";
                    getline(cin,bcd);
                    getline(cin,bcd);

                    bcdd=bcdtd(bcd); //bcd to decimal conversion
                    cout<<"\nThe Binary equivalent : ";
                    dtb(bcdd); //decimal to binary conversion

                }
                while (option3==2) //binary code decimal to binary coded decimal selected>>>>>>>>>>>>>>>>>>>>>
                {
                    cout<<"\n\nYour number is already a binary coded decimal. \nPlease choose another : ";
                    cin>>option3;
                    if ((option3 < 1) || (option3 > 6)){option3 = 2;} //loop for redundant choice
                }
                if (option3==3) //binary coded decimal to octal selected>>>>>>>>>>>>>>>
                {
                    int bcdd, oct; //variable declarations
                    string bcd;
                    cout<<"\n\n---------BINARY CODED DECIMAL TO OCTAL CONVERSION---------";
                    cout<<"\nEnter the binary coded decimal number to be converted : ";
                    getline(cin,bcd);
                    getline(cin,bcd);

                    bcdd=bcdtd(bcd); //bcd to decimal conversion
                    cout<<"\nThe Octal equivalent : ";
                    oct = DToO(bcdd); //decimal to octal conversion
                }
                if (option3==4) //binary coded decimal to hexadecimal selected>>>>>>>>>>>>>>>
                {
                    int bcdd, hex; //variable declarations
                    string bcd;
                    cout<<"\n\n-------BINARY CODED DECIMAL TO HEXADECIMAL CONVERSION-------";
                    cout<<"\nEnter the binary coded decimal number to be converted : ";
                    getline(cin,bcd);
                    getline(cin,bcd);

                    bcdd=bcdtd(bcd); //bcd to decimal conversion
                    cout<<"\nThe Hexadecimal equivalent : ";
                    hex = DToH(bcdd); //hexadecimal to decimal conversion

                }
                if (option3==5) //binary coded decimal to decimal selected>>>>>>>>>>>>>>>
                {
                    int bcdd; //variable declarations
                    string bcd;
                    cout<<"\n\n---------BINARY CODED DECIMAL TO DECIMAL CONVERSION---------";
                    cout<<"\nEnter the binary coded decimal number to be converted : ";
                    getline(cin,bcd);
                    getline(cin,bcd);

                    bcdd=bcdtd(bcd); //bcd to decimal conversion
                    cout<<"\nThe Decimal equivalent : "<<bcdd;
                }
                cout<<"\n\nDo you want to do another conversion?";
                restartb=opt2(restartb); //loop condition assignment
            }

            //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
            if (option2==3) //Octal conversion----------------------------------------------------------------
            {
                cout<<"\n- To : ";
                cin>>option3;
                option3=check6(option3);

                if (option3==1) //octal to binary selected>>>>>>>>>>>>>>>
                {
                    char oct[20];
                    int y, bin;
                    cout<<"\n-------------OCTAL TO BINARY CONVERSION-------------";
                    cout<<"\nPlease Enter the Octal Number to convert : ";
                    cin>>oct;
                    y = OToD(oct);
                    cout<<"\nThe binary equivalent : ";
                    bin=dtb(y);

                }
                if (option3==2) //octal to binary coded decimal selected>>>>>>>>>>>>>>>
                {
                    char oct[20];
                    int bcd;
                    int y;
                    cout<<"\n------OCTAL TO BINARY CODED DECIMAL CONVERSION------";
                    cout<<"\nPlease Enter the Octal Number to convert : ";
                    cin>>oct;
                    y = OToD(oct);

                    stringstream ss;
                    ss<<y;
                    string s;
                    ss>>s;

                    cout<<"\nThe binary coded decimal equivalent : ";
                    bcd = dtbcd(s);

                }
                while (option3==3) //octal to octal selected>>>>>>>>>>>>>>>>>>>>>
                {
                    cout<<"\nYour number is already a octal. \nPlease choose another : ";
                    cin>>option3;
                    if ((option3 < 1) || (option3 > 6)){option3 = 3;} //loop for redundant choice
                }
                if (option3==4) //octal to hexadecimal selected>>>>>>>>>>>>>>>
                {
                    char OctNum[20];
                    int yy;
                    cout<<"\n-----------OCTAL TO HEXADECIMAL CONVERSION-----------";
                    cout<<"\nPlease enter the Octal number to convert : ";
                    cin>>OctNum;

                    yy = OToD(OctNum);
                    cout<<"\nThe hexadecimal equivalent  :  ";
                    DToH(yy);
                }
                if (option3==5) //octal to decimal selected>>>>>>>>>>>>>>>
                {
                    int u;
                    char Octnum[20];
                    cout<<"\n-------------OCTAL TO DECIMAL CONVERSION-------------";
                    cout<<"\nPlease enter the Octal number to convert : ";
                    cin>>Octnum;

                    u=OToD(Octnum);
                    cout<<"\nThe decimal equivalent  :  "<<u;
                }
                cout<<"\n\nDo you want to do another conversion?";
                restartb=opt2(restartb); //loop condition assignment
            }

            //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
            if (option2==4) //Hexadecimal conversion----------------------------------------------------------------
            {
                cout<<"\n- To : ";
                cin>>option3;
                option3=check6(option3);

                if (option3==1) //hexadecimal to binary selected>>>>>>>>>>>>>>>
                {
                    char Hexa1[20];
                    int y, bin;
                    cout<<"\n----------HEXADECIMAL TO BINARY CONVERSION----------";
                    cout<<"\nPlease enter the Hexadecimal number to convert : ";
                    cin>>Hexa1;

                    y = HToD(Hexa1);
                    cout<<"\nBinary equivalent  :  ";
                    bin=dtb(y);
                }
                if (option3==2) //hexadecimal to binary coded decimal selected>>>>>>>>>>>>>>>>>>>>>>>>>
                {
                    char hex[20];
                    int y, bcd;
                    cout<<"\n---HEXADECIMAL TO BINARY CODED DECIMAL CONVERSION---";
                    cout<<"\nPlease Enter the Hexadecimal Number to convert : ";
                    cin>>hex;

                    y = HToD(hex);

                    stringstream ss;
                    ss<<y;
                    string s;
                    ss>>s;

                    cout<<"\nThe binary coded decimal equivalent : ";
                    bcd = dtbcd(s);

                }
                if (option3==3) //hexadecimal to octal selected>>>>>>>>>>>>>>>>>>>>>>>>>>
                {
                    char Hexa1[20];
                    int y;
                    cout<<"\n----------HEXADECIMAL TO OCTAL CONVERSION----------";
                    cout<<"\nPlease enter the Hexadecimal number to convert : ";
                    cin>>Hexa1;

                    y = HToD(Hexa1);
                    cout<<"\nThe octal equivalent  :  ";
                    DToO(y);

                }
                while (option3==4) //hexadecimal to hexadecimal selected>>>>>>>>>>>>>>>>>>>>>
                {
                    cout<<"\nYour number is already a hexadecimal. \nPlease choose another : ";
                    cin>>option3;
                    if ((option3 < 1) || (option3 > 6)){option3 = 4;} //loop for redundant choice
                }
                if (option3==5) //hexadecimal to decimal selected>>>>>>>>>>>>>>>
                {
                    char Hexa[20];
                    int y;
                    cout<<"\n----------HEXADECIMAL TO DECIMAL CONVERSION----------";
                    cout<<"\nPlease enter the Hexadecimal number to convert : ";
                    cin>>Hexa;

                    y=HToD(Hexa);
                    cout<<"\nThe decimal equivalent  :  "<<y;

                }
                cout<<"\n\nDo you want to do another conversion?";
                restartb=opt2(restartb); //loop condition assignment
            }

            //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
            if (option2==5) //Decimal conversion-----------------------------------------------------------------------------
            {
                cout<<"\n- To : ";
                cin>>option3;
                option3=check6(option3);

                if (option3==1) //Decimal to binary conversion selected>>>>>>>>>>>>>>>>>>>
                {
                    int bin;
                    cout<<"\n-------------DECIMAL to BINARY conversion-------------";
                    cout<<"\nEnter the decimal number : ";
                    cin>>bin;

                    cout<<"\nThe binary equivalent : ";
                    dtb(bin); //decimal to binary function call

                }

                if (option3==2) //Decimal to binary coded decimal selected>>>>>>>>>>>>>>>
                {
                    string bcdc;
                    cout<<"\n------DECIMAL to BINARY CODED DECIMAL conversion------";
                    cout<<"\nPlease enter the decimal number to convert : ";
                    getline(cin,bcdc);
                    getline(cin,bcdc);

                    cout<<"\nThe binary coded decimal equivalent  :  ";
                    dtbcd(bcdc); //decimal tobcd function call
                }

                if (option3==3) //Decimal to Octal selected>>>>>>>>>>>>>>>
                {
                    char deciNumber; //variable declaration
                    cout<<"\n--------------DECIMAL to OCTAL conversion-------------";
                    cout<<"\nPlease enter the decimal number to convert : ";
                    cin>>deciNumber;
                    cout<<"\nThe octal equivalent  :  ";
                    DToO(deciNumber); //decimal to octal function call
                }

                if (option3==4) //Decimal to Hexadecimal selected>>>>>>>>>>>>>>>
                {
                    int deci; //variable declaration
                    cout<<"\n----------DECIMAL to HEXADECIMAL conversion-----------";
                    cout<<"\nPlease enter the decimal number to convert : ";
                    cin>>deci;
                    cout<<"\nBinary Coded Decimal equivalent  :  ";
                    DToH(deci); //decimal to hexadecimal function call
                }

                while (option3==5) //decimal to decimal selected>>>>>>>>>>>>>>>>>>>>>
                {
                    cout<<"\nYour number is already a decimal. \nPlease choose another : ";
                    cin>>option3;
                    if ((option3 < 1) || (option3 > 6)){option3 = 5;} //loop for redundant choice
                }
                cout<<"\n\nDo you want to do another conversion?";
                restartb=opt2(restartb); //loop condition assignment
            }//------------------------------------------------------------


    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    if (option2==6 || option3==6) //Return to Main Menu-------------------------------------------
    {
        cout<<"\n\n"; //space where main menu will restart after
        restartb = 0; //holding value
        menu = 1; //main menu loop condition assignment
        option = 0; //holding value
    }
            //****************************************************************
        }

    }

    if (restartb==2) //user does not want to do another operation.
    {
        option=0; //holding value
        menu = Menu(menu);//main menu function call.
        cout<<"\n\n"; //space after which main menu will restart or ending message will be printed
    }

if (option==6) //if exit is selected.
    {
        cout<<"\nThank you for using this program.\n\n\n"; //Ending message
        return 0; //end of program.
    }
}
    if (menu == 2) //if user does not wish to return to main menu.
    {
        cout<<"\nThank you for using this program.\n\n\n"; //Ending message
        return 0; //end of program.
    }
}
