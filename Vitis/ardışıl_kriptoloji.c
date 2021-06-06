#include <stdio.h>
#include "xparameters.h"
#include "xkeyexchange.h"
#include "xanahtaruretimi.h"
#include "xaes.h"
#include "xinvaes.h"

int main()
{
int a,c;
int doneAES;
int s,s1,s2,s3;
int result0[11],result1[11],result2[11],result3[11];
int done;
int decrypted,decrypted1,decrypted2,decrypted3;
int KEresult,KEresult1,KEresult2,KEresult3,KEresult4,KEresult5,KEresult6,KEresult7;


			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x10, 0x1BB9AF40); // 10-2c modN //465153856
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x14, 0x35535E97);//894656151
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x18, 0x10F71001);//284626945
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x1c, 0x16ECF101);//384626945
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x20, 0x1CE2D201);//484626945
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x24, 0x22D8B301);//584626945
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x28, 0x28CE9401);//684626945
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x2c, 0x2EC47501);//784626945


			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x34, 0x15C90571); // 34-50 ALPHA //
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x38, 0x423A35C7);//111111111
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x3c, 0x422941EF);//1110000111
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x40, 0x342DDE31);//875421233
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x44, 0x357039A1);//896547233
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x48, 0x97C5B916);//2546317590
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x4c, 0xA3A238D6);//2745317590
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x50, 0x423A35C7);//1111111111


			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x58, 0x2E6674F0); // 58-74 xA/xB  //778466544
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x5c, 0x2E669C00);//778476544
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x60, 0x34F51380);//888476544
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x64, 0x3B838B00);//998476544
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x68, 0x42AA9900);//1118476544
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x6c, 0x27221BB8);//656546744
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x70, 0x27BAB238);//666546744
			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x74, 0x2D17FCB8);//756546744



		    a=XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0xa0); //done

	while(a==0){

			XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0, 1); // start
		    a=XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0xa0);

		};

			KEresult=  XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x7c);
			KEresult1= XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x80);
			KEresult2= XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x84);
			KEresult3= XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x88);
			KEresult4= XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x8c);
			KEresult5= XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x90);
			KEresult6= XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x94);
			KEresult7= XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x98);

	////////////////////////    Anahtar Üretilmesi     /////////////////////////////

			 XAnahtaruretimi_WriteReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x10, KEresult);
			 XAnahtaruretimi_WriteReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x14, KEresult1);
			 XAnahtaruretimi_WriteReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x18, KEresult2);
			 XAnahtaruretimi_WriteReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x1c, KEresult3);


		     done =XAnahtaruretimi_ReadReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x40);
		for(int i=0;done==0;i++){

			XAnahtaruretimi_WriteReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x00, 1); // start
			done =XAnahtaruretimi_ReadReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x40);

			result0[i] = XAnahtaruretimi_ReadReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x2c);
			result1[i] = XAnahtaruretimi_ReadReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x30);
			result2[i] = XAnahtaruretimi_ReadReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x34);
			result3[i] = XAnahtaruretimi_ReadReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x38);

		};

	////////////////////////    AES       /////////////////////////////

		        XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x38, 0); //reset

	            XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x10, KEresult); // Main Key
	    		XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x14, KEresult1);
	    		XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x18, KEresult2);
	    		XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x1c, KEresult3);

	    		XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x24, 0xccddeeff);//Plain Text
	    		XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x28, 0x8899aabb);
	    		XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x2c, 0x44556677);
	    		XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x30, 0x00112233);


	    for(int i=1;i<12;i++){


		      XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x40,result0[i]); // Round Key
		      XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x44,result1[i]);
		      XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x48,result2[i]);
		      XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x4c,result3[i]);

		      XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0, 1); //start

	     };

			doneAES=XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x68);

		 while(doneAES=0) {
			 doneAES=XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x68);
		};

			 s = XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x54);
			 s1 = XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x58);
			 s2 = XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x5c);
			 s3 = XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x60);

 ////////////////////////  Inverse  AES       /////////////////////////////


 	 		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x38, 1); // Key Expansion = 1
 	 		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x40, 0); //reset


 	 		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x10,result0[10] );   //10. Round  Key
 	 		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x14,result1[10] );
 	 		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x18,result2[10] );
 	 		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x1c,result3[10] );


 	 		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x24, s); // Cipher Text
 	 		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x28, s1);
 	 		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x2c, s2);
 	 		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x30, s3);


 	 	for(int j=9;j>-2;j=j-1){

 	 		XInvaes_WriteReg(	XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x48,result0[j]); // Round  Key
 	 		XInvaes_WriteReg(	XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x4c,result1[j]);
 	 		XInvaes_WriteReg(	XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x50,result2[j]);
 	 		XInvaes_WriteReg(	XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x54,result3[j]);


 	 		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0, 1);    // inv_AES start
 	 	}


 	 		c=XInvaes_ReadReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x70);   // Done INV_AES
 	 	while( c=0) {

 	 		c=XInvaes_ReadReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x70);

 	 	};

 	 		decrypted  = XInvaes_ReadReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x5c);        //Plain Text
 	 		decrypted1 = XInvaes_ReadReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x60);
 	 		decrypted2 = XInvaes_ReadReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x64);
 	 		decrypted3 = XInvaes_ReadReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x68);

 	 	return decrypted3;
 	 	}
