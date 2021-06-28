#include "xkohonen.h"
#include "xparameters.h"
#include <stdio.h>
#include "xkeyexchange.h"
#include "xanahtaruretimi.h"
#include "xaes.h"
#include "xinvaes.h"

struct DataArray
{
	int datas[4];
};

struct DataArrays
{
	int datas0[11];
	int datas1[11];
	int datas2[11];
	int datas3[11];
};

int NeuralNetwork(int data[256])
{
	int ratio, result;
	XKohonen_WriteReg(XPAR_KOHONEN_0_S_AXI_AXILITES_BASEADDR, 0x18, 1); // enable
	XKohonen_WriteReg(XPAR_KOHONEN_0_S_AXI_AXILITES_BASEADDR, 0x20, 0); // reset

	for(int i=0;i<256;i++){
		XKohonen_WriteReg(XPAR_KOHONEN_0_S_AXI_AXILITES_BASEADDR, 0x10, data[i]); // input
		XKohonen_WriteReg(XPAR_KOHONEN_0_S_AXI_AXILITES_BASEADDR, 0, 1); // start
	}

	ratio = XKohonen_ReadReg(XPAR_KOHONEN_0_S_AXI_AXILITES_BASEADDR, 0x28);

	result = XKohonen_ReadReg(XPAR_KOHONEN_0_S_AXI_AXILITES_BASEADDR, 0x30);

	XKohonen_WriteReg(XPAR_KOHONEN_0_S_AXI_AXILITES_BASEADDR, 0x18, 0); // enable

	return ratio;
}

struct DataArray KeyExchange()
{

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

	int a = XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0xa0); //done

	while(a == 0)
	{
		XKeyexchange_WriteReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0, 1); // start
		a=XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0xa0);
	};

	KEresult =  XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x7c);
	KEresult1 = XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x80);
	KEresult2 = XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x84);
	KEresult3 = XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x88);
	KEresult4 = XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x8c);
	KEresult5 = XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x90);
	KEresult6 = XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x94);
	KEresult7 = XKeyexchange_ReadReg(XPAR_KEYEXCHANGE_0_S_AXI_AXILITES_BASEADDR, 0x98);


	struct DataArray mainKeys;
	mainKeys.datas[0] = KEresult;
	mainKeys.datas[1] = KEresult1;
	mainKeys.datas[2] = KEresult2;
	mainKeys.datas[3] = KEresult3;

	return mainKeys;

}

struct DataArrays RoundKeyExpansion(struct DataArray mainKeys)
{
	struct DataArrays roundKeys;

	////////////////////////    Anahtar Üretilmesi     /////////////////////////////

	XAnahtaruretimi_WriteReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x10, mainKeys.datas[0]);
	XAnahtaruretimi_WriteReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x14, mainKeys.datas[1]);
	XAnahtaruretimi_WriteReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x18, mainKeys.datas[2]);
	XAnahtaruretimi_WriteReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x1c, mainKeys.datas[3]);

	int done = XAnahtaruretimi_ReadReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x40);

	for(int i=0;done==0 && i<11;i++){
		XAnahtaruretimi_WriteReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x00, 1); // start
		done = XAnahtaruretimi_ReadReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x40);

		roundKeys.datas0[i] = XAnahtaruretimi_ReadReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x2c);
		roundKeys.datas1[i] = XAnahtaruretimi_ReadReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x30);
		roundKeys.datas2[i] = XAnahtaruretimi_ReadReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x34);
		roundKeys.datas3[i] = XAnahtaruretimi_ReadReg(XPAR_ANAHTARURETIMI_0_S_AXI_AXILITES_BASEADDR, 0x38);
	};

	return roundKeys;
}

struct DataArray CryptographyEncryption(struct DataArray image, struct DataArray mainKeys, struct DataArrays roundKeys)
{

	////////////////////////    AES       /////////////////////////////

	XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x38, 0); //reset

	XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x10, mainKeys.datas[0]); // Main Key
	XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x14, mainKeys.datas[1]);
	XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x18, mainKeys.datas[2]);
	XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x1c, mainKeys.datas[3]);

	XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x24, image.datas[3]);//Plain Text
	XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x28, image.datas[2]);
	XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x2c, image.datas[1]);
	XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x30, image.datas[0]);


	for(int i=1;i<11;i++){

		  XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x40,roundKeys.datas0[i]); // Round Key
		  XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x44,roundKeys.datas1[i]);
		  XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x48,roundKeys.datas2[i]);
		  XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x4c,roundKeys.datas3[i]);

		  XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0, 1); //start

	 };

	int doneAES = XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x68);

	while(doneAES==0) {
		 XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0, 1); //start
		  doneAES = XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x68);
		 };

	struct DataArray encrypted;

	encrypted.datas[0] = XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x54);
	encrypted.datas[1] = XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x58);
	encrypted.datas[2] = XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x5c);
	encrypted.datas[3] = XAes_ReadReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x60);

	return encrypted;

}

struct DataArray CryptographyDecryption(struct DataArray encrypted, struct DataArray mainKeys,  struct DataArrays roundKeys)
{

	////////////////////////  Inverse  AES       /////////////////////////////

	XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x38, 1); // Key Expansion = 1
	XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x40, 0); //reset


	XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x10,roundKeys.datas0[10] );   //10. Round  Key
	XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x14,roundKeys.datas1[10] );
	XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x18,roundKeys.datas2[10] );
	XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x1c,roundKeys.datas3[10] );


	XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x24, encrypted.datas[0]); // Cipher Text
	XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x28, encrypted.datas[1]);
	XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x2c, encrypted.datas[2]);
	XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x30, encrypted.datas[3]);


	for(int i=9;i>=0;i--){

		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x48,roundKeys.datas0[i]); // Round  Key
		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x4c,roundKeys.datas1[i]);
		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x50,roundKeys.datas2[i]);
		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x54,roundKeys.datas3[i]);

		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0, 1);    // inv_AES start
	}

	int c = XInvaes_ReadReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x70);   // Done INV_AES

	while(c==0) {
		XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0, 1);    // inv_AES start
		c = XInvaes_ReadReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x70);
	};

	struct DataArray decrypted;
	decrypted.datas[0] = XInvaes_ReadReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x5c);        //Plain Text
	decrypted.datas[1] = XInvaes_ReadReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x60);
	decrypted.datas[2] = XInvaes_ReadReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x64);
	decrypted.datas[3] = XInvaes_ReadReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x68);

	return decrypted;
}

void ResetEncryption()
{
	XAes_WriteReg(XPAR_AES_0_S_AXI_AXILITES_BASEADDR, 0x38, 1); //reset AES

}

void ResetDecryption()
{
	XInvaes_WriteReg(XPAR_INVAES_0_S_AXI_AXILITES_BASEADDR, 0x40, 1); //reset InvAES
}

int main()
{
	const int data[] = {0xc0f00000,0xc1380000,0xc0b00000,0x40d00000,0x41780000,0x3f000000,0xc0600000,0x40200000,0xc1080000,0xbf000000,0x40900000,0xbf000000,0x40b00000,0x40900000,0x3fc00000,0x40b00000,0xc0d00000,0x41580000,0x41180000,0xc0d00000,0xc0f00000,0xbfc00000,0x41480000,0x40f00000,0xc0d00000,0xc1080000,0xc0d00000,0xbf000000,0x41080000,0x40200000,0xbfc00000,0xc1080000,0x40900000,0x41280000,0xc0d00000,0xc1280000,0xc0200000,0x41080000,0xc1180000,0xc1580000,0xbfc00000,0x40200000,0xc0200000,0x40600000,0x41180000,0x40d00000,0xc0600000,0xbfc00000,0xbfc00000,0xc0600000,0x41180000,0x40600000,0xc1580000,0x40f00000,0x41380000,0xc1380000,0xc0200000,0x3fc00000,0xc0b00000,0xc0200000,0xc0900000,0x3f000000,0x40f00000,0xc0900000,0xc0600000,0x40f00000,0x40200000,0xc0b00000,0xc1180000,0x40200000,0x41080000,0x3f000000,0xc0200000,0x40d00000,0xbfc00000,0xc0d00000,0x40f00000,0x40d00000,0x3f000000,0x40b00000,0xc0900000,0x40200000,0x3fc00000,0xc1480000,0xc0200000,0xc1080000,0xc1680000,0x3f000000,0xc1380000,0xbfc00000,0xc0d00000,0xc1080000,0x41080000,0xc1780000,0xc0b00000,0x40d00000,0xc1780000,0xbfc00000,0x40600000,0xc1580000,0xbf000000,0xc1380000,0xbfc00000,0x41780000,0x40f00000,0x40900000,0x40d00000,0x40900000,0x40900000,0x40600000,0x41680000,0x3fc00000,0xc1680000,0xc0b00000,0xc1280000,0x40b00000,0x40900000,0xc0d00000,0x40200000,0x40b00000,0xc0900000,0x3fc00000,0x41380000,0x41280000,0x40d00000,0x3fc00000,0xc0200000,0x40900000,0x40d00000,0x41480000,0x41280000,0xc0600000,0x3f000000,0x40d00000,0x3f000000,0x40600000,0xc0600000,0xc1380000,0xc0900000,0x3fc00000,0x40d00000,0x40900000,0xbfc00000,0x41180000,0x41080000,0xc1180000,0xc0f00000,0xbfc00000,0x40b00000,0x41180000,0xbf000000,0x3fc00000,0x40600000,0xbfc00000,0xbfc00000,0x40d00000,0x41280000,0xc0600000,0xc0600000,0x40900000,0x40600000,0xc0600000,0x3f000000,0x40200000,0xc0f00000,0xc1180000,0xc1380000,0x40200000,0x40900000,0x40900000,0x3f000000,0xc1180000,0x3fc00000,0x41480000,0x41180000,0x41080000,0xc0600000,0xc0d00000,0x40200000,0xbf000000,0x41280000,0x41180000,0xbfc00000,0x40200000,0x40200000,0xc0f00000,0xc0d00000,0xc0d00000,0xc1080000,0xc0900000,0xc1480000,0xc0b00000,0xbf000000,0x40200000,0x3fc00000,0xc1080000,0x40b00000,0x3f000000,0xc1580000,0xc0900000,0xc1380000,0xc0b00000,0x41180000,0xc0f00000,0x40600000,0x3f000000,0xc0f00000,0x41380000,0x40b00000,0xc0d00000,0x40200000,0x3f000000,0xc1380000,0x41380000,0x41380000,0x40d00000,0x41180000,0xbf000000,0x40200000,0x40600000,0xc0d00000,0xbfc00000,0xbfc00000,0x40600000,0x40900000,0xc1680000,0x3fc00000,0xbf000000,0xc0f00000,0xbfc00000,0xc1280000,0x40200000,0x40f00000,0xbfc00000,0x40600000,0xc0f00000,0xc1280000,0xbf000000,0xc0900000,0xc0900000,0xc1280000,0xc1280000,0xc0900000,0x40900000,0x41680000,0x40900000,0xc0b00000,0x3f000000,0xc1680000,0xc0f00000,0x40d00000,0xc0900000,0x40600000,0x40900000,0xbf000000,0x40b00000};

	struct DataArray mainKeys = KeyExchange();
	struct DataArrays roundKeys = RoundKeyExpansion(mainKeys);

	int ratio = NeuralNetwork(data);

	struct DataArray encrypted;
	struct DataArray decrypted;

	if(ratio > 0.3){ // kontrol %30

			struct DataArray image;
			for(int f=0;f<4;f++)
			{
				image.datas[f] = data[f];
			}

			encrypted = CryptographyEncryption(image, mainKeys, roundKeys);
			decrypted = CryptographyDecryption(encrypted, mainKeys, roundKeys);
	}

    return encrypted;
}







//ResetEncryption();
			//ResetDecryption();
