#include <stdio.h>
#include "xparameters.h"
#include "xkeyexchange.h"
#include "xaes.h"
#include "xinv_aes.h"


int main()
{
int a,b,c,d,e;
int result,result1,result2,result3,result4,result5,result6,result7;  // KeyEx sonucu
int encrypted,encrypted1,encrypted2,encrypted3;

		                    /////////////KEY EXCHANGE //////////////

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

		   result=  XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x7c);
		   result1= XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x80);
		   result2= XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x84);
		   result3= XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x88);
		   result4= XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x8c);
		   result5= XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x90);
		   result6= XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x94);
		   result7= XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x98);


		                    ///////////// AES //////////////



		 XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x00010, 0xccddeeff);  //þifrelenecek metin
		 XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x00014, 0x8899aabb);
		 XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x00018, 0x44556677);
		 XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x0001c, 0x00112233);

		 XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x00024,result1); //anahtar
		 XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x00028,result3);
		 XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x0002c,result5);
		 XAes_WriteReg(	XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x00030,result7);

		 XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x0000, 1);     // AES START

		 b=XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x00048);   //Þifrelenmiþ metin VALÝD

		 while(b=0) {
		     b=XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x00048);
		 				};

		 encrypted  = XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x00038);  //Þifrelenmiþ metin (AES)
		 encrypted1 = XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x0003c);
		 encrypted2 = XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x00040);
		 encrypted3 = XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x00044);


		 c=XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x0005c);   //10 döngü sonucu oluþan anahtar valid deðeri
	     while(c=0) {                                                   //10 döngü sonucu oluþan anahtar

	        c=XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x0005c);
 				};
         XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x0004c);
	     XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x00050);
	     XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x00054);
	     XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x00058);


			 		   /////////////INV_AES //////////////


		 XInv_aes_WriteReg(	XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x10, encrypted);
		 XInv_aes_WriteReg(	XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x14, encrypted1);
		 XInv_aes_WriteReg(	XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x18, encrypted2);
		 XInv_aes_WriteReg(	XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x1c, encrypted3);

		 XInv_aes_WriteReg(	XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x24,result1); // 128- main key
		 XInv_aes_WriteReg(	XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x28,result3);
		 XInv_aes_WriteReg(	XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x2c,result5);
		 XInv_aes_WriteReg(	XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x130,result7);

		 XInv_aes_WriteReg(XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0, 1);    // inv_AES START

		  d=XInv_aes_ReadReg(XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x48);   // þifresi çözülmüþ metin VALÝD
		  while( d=1) {

		 	 d=XInv_aes_ReadReg(XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x48);
		  				};

		  XInv_aes_ReadReg(XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x38);    //Dencryption text
		  XInv_aes_ReadReg(XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x3c);
		  XInv_aes_ReadReg(XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x40);
		  XInv_aes_ReadReg(XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x44);

		  e=XInv_aes_ReadReg(XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x5c);   //10 döngü sonucu oluþan anahtar VALÝD

		  while( e=1) {

		 	 e=XInv_aes_ReadReg(XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x5c);
		  				};

		  XInv_aes_ReadReg(XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x4c);        //10 döngü sonucu oluþan anahtar
		  XInv_aes_ReadReg(XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x50);
		  XInv_aes_ReadReg(XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x54);
		  XInv_aes_ReadReg(XPAR_INV_AES_0_S_AXI_AXILITES_BASEADDR, 0x58);

		     return 0;
		 }

