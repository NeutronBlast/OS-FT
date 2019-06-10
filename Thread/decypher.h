void desencriptar(char message[], int inicio, int fin){
    int aux = inicio;
	char ch;
	
	for(inicio; inicio<=fin; inicio++){
		ch = message[inicio];
		
		if(ch >= 'a' && ch <= 'z'){
			ch = ch - 2;
			
			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1;
			}
			
			message[inicio] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - 2;
			
			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1;
			}
			
			message[inicio] = ch;
		}
	}
}

void desencriptarM(char message[],int i, int fin){
    int aux = i;
	
	for (i; i<=fin; i++){
		switch(message[i]){
			
			{case '0':
				message[i]=109;
				break;	
			}
			
			{case '1':
				message[i]=117;
				break;	
			}
			
			{case '2':
				message[i]=114;
				break;	
			}
			
			{case '3':
				message[i]=99;
				break;	
			}
			
			{case '4':
				message[i]=105;
				break;	
			}
			
			{case '5':
				message[i]=101;
				break;	
			}
			
			{case '6':
				message[i]=108;
				break;	
			}
			
			{case '7':
				message[i]=97;
				break;	
			}
			
			{case '8':
				message[i]=103;
				break;	
			}
			
			{case '9':
				message[i]=111;
				break;	
			}
		}
	}
	
}
