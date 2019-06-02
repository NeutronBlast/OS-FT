void encriptar(char message[], int inicio, int nc){
	int fin = inicio+nc;
    int aux = inicio;
	char ch;	
	for(inicio; inicio<fin; inicio++){
		ch = message[inicio];
		
		if(ch >= 'a' && ch <= 'z'){
			ch = ch + 2;
			
			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}
			
			message[inicio] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + 2;
			
			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}
			
			message[inicio] = ch;
		}
	}

    /*printf("Encrypted part\n");
    for (aux; aux<fin; aux++){
	printf("%c", message[aux]);
    }
    printf("\n");*/
	
}