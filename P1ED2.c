#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t
#include <stdio.h>
#include <stdlib.h>

#define EXPERIMENT 0 
#define RUN 2
//tim
void insertionSort(int arr[], int l, int r) {
    if (arr == NULL || l>=r) return;
    
    int key; 
    int i, j;
    for (i=l+1; i<=r; i++) {
        key = arr[i];
        j = i-1;
        while (j>=l && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
}


void merge(int arr[], int temp[], int l, int m, int r){
    if (arr == NULL || temp == NULL) return;
    
    if (l > m || m+1 > r) return;

    int i = l;
    int j = m + 1;
    int start = l;

    
    while (i <= m && j <= r){
	if (arr[i] < arr[j]){
	    temp[start++] = arr[i++];
	} else if (arr[i] == arr[j]){
	    temp[start++] = arr[i++];
	    temp[start++] = arr[j++];
	}
	else{
	    temp[start++] = arr[j++];
	}
	
    }

    
    while (i <= m){
	    temp[start++] = arr[i++];
    }

    
    while (j <= r){
	    temp[start++] = arr[j++];
    }

    for (i = l; i <= r; i++){
	    arr[i] = temp[i];
    }
}


int min(int arg1, int arg2){
    if (arg1 <= arg2){
        return arg1;
    } else {
        return arg2;
    }
} 


void timSort(int arr[], unsigned int size){
    if (arr == NULL || size <= 1) return;
    int i;
    
    for (i=0; i < size; i+=RUN){
        insertionSort(arr, i, min(i+RUN-1, size-1));
    }
    
    int* temp = (int*)malloc(sizeof(int)*size);

    
    int l, m, r, n;                 
    for (n=RUN; n < size; n*=2){
        for (l=0; l < size; l+=2*n){
            m = l+n-1;
            r = min(l+2*n-1, size-1);
            if (m<r){
                merge(arr, temp, l, m, r);
            }
        }
    }
    free(temp);
}


void printIntArray(int arr[], unsigned int size){
  unsigned int i; 
  for(i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}
//tim


//mergeSort

void merget(int *vetor1, int *vetor2, int start, int mid, int end) {

	int i = start, j = mid+1, k = 0;

	while(i <= mid && j <= end) {
		if(vetor1[i] <= vetor1[j]) {
			vetor2[k] = vetor1[i];
			k += 1; i += 1;
		}
		else {
			vetor2[k] = vetor1[j];
			k += 1; j += 1;
		}
	}

	while(i <= mid) {
		vetor2[k] = vetor1[i];
		k += 1; i += 1;
	}

	while(j <= end) {
		vetor2[k] = vetor1[j];
		k += 1; j += 1;
	}

	for(i = start; i <= end; i += 1) {
		vetor1[i] = vetor2[i - start];
	}
}

void sort(int *vetor1, int *vetor2, int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		sort(vetor1, vetor2, start, mid);
		sort(vetor1, vetor2, mid + 1, end);
		merget(vetor1, vetor2, start, mid, end);
	}
}

void mergesort(int *vetor1, int tamanho) {
    int *vetor2 = malloc(sizeof(int) * tamanho);
    sort(vetor1, vetor2, 0, tamanho - 1);
    free(vetor2);
}

//mergeSort

//heapsort

void menu(int *array[], int qtd)
{
    int opc;
    do
    {
        printf("\n========================================== PROGRAMA ORDENA VETOR ==========================================");
        printf("\n\n\n   Ordeno o vetor de forma:\n\n    1 - Crescente (Heap Sort Maximo)\n\n    2 - Decrescente (Heap Sort Minimo)\n\n    3 - Sair do programa");
        printf("\n\n=========================================================================================================\n");
        printf("\n\n  Opcao: ");
        scanf("%d", &opc);
        system("cls");
        switch(opc)// switch case das opcoes do vetor
        {
        case 1:
            opcaoCrescente(opc, array, qtd);
            system("pause");
            system("cls");
            break;
        case 2:
            opcaoDecrescente(opc,array);
            system("pause");
            system("cls");
            break;

        case 3:
            printf("\n\n=========================================================================================================\n");
            printf("\n\n                    ENCERRANDO O PROGRAMA, AGUARDE...\n");
            printf("\n\n=========================================================================================================\n\n\n");
            break;

        default:
            printf("\n\n Insira uma opcao valida!!\n\n\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(opc!=3);
}

// HEAPFY
void heapfy1(int *vet,int n, int i)// heapfy1 corresponde ao heapfy da opcao 1(Heap Maior/Crescente)
{
    int esq =2*i+1;
    int dir =2*i+2;
    int maior,aux;

    //escolhe maior valor entre os filhos (esq e dir)
    maior = i;
    if((esq < n) && (vet[esq] > vet[maior]))
        maior = esq;
    if((dir < n) && (vet[dir] > vet[maior]))
        maior = dir;

    //se um dos filhos for maior que o pai, troca.
    if(maior != i)
    {
        aux = vet[i];
        vet[i] = vet[maior];
        vet[maior]=aux;

        //continua descida até o local adequado, o elemento trocado
        //é comparado com seus filhos, para o maior elemento ser o pai
        //isso é feito para que o pai sempre seja maior que os filhos.
        heapfy1(vet, n, maior);
    }
}

void heapfy2( int *vet, int n, int i)// heapfy2 corresponde ao heapfy da opcao 2(Heap Menor/Decrescente)
{
    int esq =2*i+1;
    int dir =2*i+2;
    int menor, aux;

    //escolhe menor valor entre os filhos (esq e dir)
    menor = i;
    if((esq < n) && (vet[esq] < vet[menor]))
        menor = esq;
    if((dir < n) && (vet[dir] < vet[menor]))
        menor = dir;

    //se um dos filhos for menor que o pai, troca.
    if(menor != i)
    {
        aux = vet[i];
        vet[i] = vet[menor];
        vet[menor]=aux;

        //continua descida até o local adequado, o elemento trocado
        //é comparado com seus filhos, para o menor elemento ser o pai
        //isso é feito para que o pai sempre seja menor que os filhos.
        heapfy2(vet, n, menor);
    }
}

//CRIA HEAP

void create_heap(int *vet, int n, int opc)
{
    int i;
    //For que irá olhar só para os nós pais
    for(i=n/2-1; i>=0; i--)
    {
        //O if sera responsavel por indicar qual Heapfy devera ser feito de acordo com a opcao escolhida
        if(opc == 1)
        {
            heapfy1(vet,n,i);//organiza o heap maximo
        }
        if(opc == 2)
        {
            heapfy2(vet,n,i);//organiza o heap minimo
        }

    }
}

void heapsort(int *vet, int n, int opc)
{
    int aux,i;
    //O create_heap faz a primeira organização para uma heap
    create_heap(vet,n, opc);
    imprimeVetor(vet);//imprime o primeiro heap
    for(i=n-1; i>0; i--)
    {
        //Troca maior(opcao 1)/menor(opcao 2) elemento(primeiro elemento do vetor) com o ultimo
        aux=vet[0];
        vet[0]=vet[i];
        vet[i]=aux;
        n--; //diminuindo o tamanho do vetor, pois o ultimo elemento do vetor já é o maior(opcao 1)/menor(opcao 2)

        //O if sera responsavel por indicar qual Heapfy devera ser feito de acordo com a opcao escolhida
        if(opc == 1)
        {
            heapfy1(vet,n,0);//Chama o heapfy para organizar a heap maximo
        }
        if(opc == 2)
        {
            heapfy2(vet,n,0);//Chama o heapfy para organizar a heap minimo
        }
    }
}

// IMPRESSAO

void opcaoDecrescente(int opc, int *vet[])
{
    
    printf("\n\n========================================== HEAP SORT MINIMO =============================================\n");
    printf("\n Vetor desordenado:   ");
    imprimeVetor(vet);
    printf("\n\n================================= COLOCANDO O VETOR EM ORDEM DECRESCENTE =================================\n");
    printf("\n\n Primeiro Heap minimo: ");
    heapsort(vet, 10, opc);
    printf("\n\n\n Vetor ja ordenado pelo Heap Sort minimo:   ");
    imprimeVetor(vet);
    printf("\n\n\n==========================================================================================================\n");
}

void opcaoCrescente(int opc, int*array[], int qtd)
{
    
    printf("\n\n========================================== HEAP SORT MAXIMO =============================================\n");
    printf("\n Vetor desordenado:   ");
    imprimeVetor(array);
    printf("\n\n================================== COLOCANDO O VETOR EM ORDEM CRESCENTE ==================================\n");
    printf("\n\n Primeiro Heap maximo: ");
    heapsort(array, qtd, opc);
    printf("\n\n\n Vetor ja ordenado pelo Heap Sort maximo:   ");
    imprimeVetor(array, qtd);
    printf("\n\n\n==========================================================================================================\n");
}

void imprimeVetor(int *vet, int qtd)// funcao de impressao do vetor
{
    int i;
    for(i = 0; i < qtd; i++)
    {
        printf("  %d  ", vet[i]);
    }
    printf("\n");
}

//heapsort

//quicksort

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

//quicksort

//radixsort

int get_max (int a[], int n){
   int max = a[0];
   int i;
   for (i = 1; i < n; i++){
   		if (a[i] > max){
   			max = a[i];
		   }
   }        
   return max;
}
void radix_sort (int a[], int n){
   int bucket[10][10], bucket_cnt[10];
   int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
   lar = get_max (a, n);
   while (lar > 0){
      NOP++;
      lar /= 10;
   }
   for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }

 for (i = 0; i < n; i++){
         r = (a[i] / divisor) % 10;
         bucket[r][bucket_cnt[r]] = a[i];
         bucket_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            a[i] = bucket[k][j];
            i++;
         }
      }
      divisor *= 10;
      printf ("Depois da passagem %d : ", pass + 1);
      for (i = 0; i < n; i++)
         printf ("%d ", a[i]);
      printf ("\n");
   }
}

//radixsort

//coutingSort

void CoutingSort(int *array, int n)
{
	int i;

	// Encontrando o maior elemento do array

	int max=array[0];
	for(i = 0; i<n; i++){
		if(array[i]>max)
		max=array[i];
	}
	int VetorIndexA[max+1];

	// Inicializando o contador do array com todos os valores sendo zeros

	for(i=0;i<=max;i++)	{
		VetorIndexA[i]=0;
	}

	// Acumular a quantidade de vezes que cada número se repete no array

	for(i=0;i<n;i++){
		VetorIndexA[array[i]]++;
	}

	// Atualizar o contador do array

	for(i=1; i<=max;i++){
		VetorIndexA[i] = VetorIndexA[i]+VetorIndexA[i-1];
	}

	// Encontrando o indice de cada elemento

    int VetorIndexB[n];
	for(i=n-1; i>=0; i--){
		VetorIndexB[--VetorIndexA[array[i]]]=array[i];
	}

	// copiar os elementos do array original para o array b

	for(i=0;i<n;i++){
		array[i]=VetorIndexB[i];
	}
}

void Exibe_Vetor(int *vetor, int tamanho ){
    int seq;
    for(seq = 0; seq < tamanho; seq++){
        printf(" %i",vetor[seq]);
        if(seq < tamanho - 1) printf(", ");
        else printf("\n");
    }
}

//coutingSort

//bublesort

void swap(int *ap, int *bp){
      int temp = *ap;
      *ap = *bp;
      *bp = temp;
}

//function to implement buuble Sort
void bubbleSort(int arr[], int size){
      int i,j;
      for(i = 0; i < size; i++){
            //last elements already in place
            for(j = 0; j < size-i-1; j++){
                  if(arr[j] > arr[j+1])
                        swap(&arr[j], &arr[j+1]);
            }
      }
}

//function to print array
void printArray(int arr[], int size){
      int i;
      for(i = 0; i < size ; i++){
              printf("%d ",arr[i]);
      }
}      

//bublesort

//insertionsort

int insertionsort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp = a[i];
        j = i-1;
        
        while(j>=0 && a[j]>temp)
            {
                a[j+1]=a[j];
                j--;
            }
        a[j+1]=temp;
        
    }
}

int displayresult(int a[],int n)
{
    int i;
    printf("\nNumbers after getting sorted :\t");
    for(i=0;i<=n;i++)
    {
        printf("\n%d",a[i]);
    }
}

//insertionsort

//selectionsort

void selection(int *vetor, int tamanho){
 int i = 0, j;
 int menor, aux;

 /*for para percorrer todos os dados do vetor*/
 for(i = 0; i  < tamanho-1; i++){
  menor = i; /*atribuição do menor valor*/
  for(j = i+1; j < tamanho; j++){ /*percorre do menor ao final do vetor comparando e guardando o menor valor*/
    if(vetor[j] < vetor[menor])
     menor = j;    
  }
  if(menor != i){ /*troca de posições*/
    aux = vetor[i];
    vetor[i] = vetor[menor];
    vetor[menor] = aux;
  }
 }
}

//selectionsort

//shellsort

void insertionSortShell(int *V, int size)
{int i,j;
    for (i = 0; i < size; i++)
    {
        for (i = 0; i < size; i++)
        {
            printf("array[%d]: %d | ", i, V[i]);
        }
        printf("\n");
        if (V[i] > V[i + 1])
        {
            int aux = V[i + 1];
            V[i + 1] = V[i];
            V[i] = aux;
        }

        for (j = i; j > 0; j--)
        {
            if (V[j] < V[j - 1])
            {
                int aux = V[j];
                V[j] = V[j - 1];
                V[j - 1] = aux;
            }
        }
    }
}

void shellSort(int *V, int H, int size)
{int i;
    printf("No shell:");
    for (i = 0; i < size; i++)
    {
        printf("array[%d]: %d | ", i, V[i]);
    }
    printf("\n");
    if (H == 1)
    {
        insertionSortShell(V, size);
    }
    else
    {int i;
        for (i = 0; i < size - H; i++)
        {
            if (V[i] > V[i + H])
            {
                int aux = V[i];
                V[i] = V[i + H];
                V[i + H] = aux;
            }
        }
        shellSort(V, H - 1, size);
    }
}


//shellsort

//beadsort

void bead_sort(int *a, int len)
{
    int i, j, max, sum;
    unsigned char *beads;
#   define BEAD(i, j) beads[i * max + j]
    for (i = 1, max = a[0]; i < len; i++)
        if (a[i] > max) max = a[i];
    beads = calloc(1, max * len);
    /* mark the beads */
    for (i = 0; i < len; i++)
        for (j = 0; j < a[i]; j++)
            BEAD(i, j) = 1;
    for (j = 0; j < max; j++) {
        /* count how many beads are on each post */
        for (sum = i = 0; i < len; i++) {
            sum += BEAD(i, j);
            BEAD(i, j) = 0;
        }
        /* mark bottom sum beads */
        for (i = len - sum; i < len; i++) BEAD(i, j) = 1;
    }
    for (i = 0; i < len; i++) {
        for (j = 0; j < max && BEAD(i, j); j++);
        a[i] = j;
    }
    free(beads);
}

//beadsort



int opt2(int op){
	int res;
	switch(op){
		case 1:
			res = 1000;
			break;
		case 2:
			res = 5000;
			break;
		case 3:
			res = 10000;
			break;
		case 4:
			res = 20000;
			break;
		case 5:
			res = 50000;
			break;
		case 6:
			res = 100000;
			break;
	}
	
	return res;
}


int main(){
	
	int opcao,op,i, j;
	float tempo;
	clock_t t1, t2;
	
	srand(time(NULL));
	int *array;
	
	printf("Escolha:\n1 - TimSort\n2 - MergeSort\n3 - HeapSort\n4 - QuickSort\n5 - RadixSort\n6 - CoutingSort\n7 - BubbleSort\n8 - InsertionSort\n9 - SelectionSort\n10 - ShellSort\n11 - BeadSort.");
	printf("\nOpcao: ");
	scanf("%d", &opcao);
	switch(opcao){
		
		case 1: //timsort
		
		printf("\nQuantidade de numeros a serem lidos:\nDigite 1 para ler 1000 numeros\nDigite 2 para ler 5000 numeros\nDigite 3 para ler 10000 numeros\nDigite 4 para ler 20000 numeros\nDigite 5 para ler 50000 numeros\nDigite 6 para ler 100000 numeros\n");
		scanf("%d", &op);
		int qtd = opt2(op);
		array = (int*)malloc(qtd * sizeof(int));
		
		
		for(i=0; i<qtd; i++){
			*(array + i) = rand() % qtd;
		}
				
		t1 = clock();
		for(i=0; i<1; i++){
			timSort(array, qtd);
		}
		t2 = clock();
		printIntArray(array, qtd);
		
		break;
		case 2: //merge
		
		printf("\nQuantidade de numeros a serem lidos:\nDigite 1 para ler 1000 numeros\nDigite 2 para ler 5000 numeros\nDigite 3 para ler 10000 numeros\nDigite 4 para ler 20000 numeros\nDigite 5 para ler 50000 numeros\nDigite 6 para ler 100000 numeros\n");
		scanf("%d", &op);
		qtd = opt2(op);
		array = (int*)malloc(qtd * sizeof(int));
		
		for(i=0; i<qtd; i++){
			*(array + i) = rand() % qtd;
		}
		
		t1 = clock();
		for(i=0; i<1; i++){
			mergesort(array, qtd);
		}
		t2 = clock();
		
		for (i = 0; i < qtd; i++) {
        printf("%d ", array[i]);
    }
    break;
    case 3://heapsort
    
    	printf("\nQuantidade de numeros a serem lidos:\nDigite 1 para ler 1000 numeros\nDigite 2 para ler 5000 numeros\nDigite 3 para ler 10000 numeros\nDigite 4 para ler 20000 numeros\nDigite 5 para ler 50000 numeros\nDigite 6 para ler 100000 numeros\n");
		scanf("%d", &op);
		qtd = opt2(op);
		array = (int*)malloc(qtd * sizeof(int));
		
		for(i=0; i<qtd; i++){
			*(array + i) = rand() % qtd;
		}
    	t1 = clock();
    	menu(array, qtd);
    	t2 = clock();
    	printf("tam: %d",array );
		break;
		case 4: //quicksort
		
		printf("\nQuantidade de numeros a serem lidos:\nDigite 1 para ler 1000 numeros\nDigite 2 para ler 5000 numeros\nDigite 3 para ler 10000 numeros\nDigite 4 para ler 20000 numeros\nDigite 5 para ler 50000 numeros\nDigite 6 para ler 100000 numeros\n");
		scanf("%d", &op);
		qtd = opt2(op);
		array = (int*)malloc(qtd * sizeof(int));
		
		
		for(i=0; i<qtd; i++){
			*(array + i) = rand() % qtd;
		}
		
		t1 = clock();
		for(i=0; i<1; i++){
			quick_sort(array, 0, qtd - 1);
		}
		t2 = clock();		
			
		
			
		printf("\nValores ordenados");
			 for(i = 0; i < qtd; i++)
			 {
			  printf(" %d", array[i]);
			 }
		break;
		
		case 5: //radixsort
		
		printf("\nQuantidade de numeros a serem lidos:\nDigite 1 para ler 1000 numeros\nDigite 2 para ler 5000 numeros\nDigite 3 para ler 10000 numeros\nDigite 4 para ler 20000 numeros\nDigite 5 para ler 50000 numeros\nDigite 6 para ler 100000 numeros\n");
		scanf("%d", &op);
		qtd = opt2(op);
		array = (int*)malloc(qtd * sizeof(int));
		
		
		for(i=0; i<qtd; i++){
			*(array + i) = rand() % qtd;
		}
		
		t1 = clock();
		for(i=0; i<1; i++){
			radix_sort (array, qtd);
		}
		t2 = clock();
		   printf ("Itens : ");
		   for (i = 0; i < qtd; i++){
		   	printf ("%d ", array[i]);
		   }
		      
		  break;
		  
		case 6: //CountingSort
		
		printf("\nQuantidade de numeros a serem lidos:\nDigite 1 para ler 1000 numeros\nDigite 2 para ler 5000 numeros\nDigite 3 para ler 10000 numeros\nDigite 4 para ler 20000 numeros\nDigite 5 para ler 50000 numeros\nDigite 6 para ler 100000 numeros\n");
		scanf("%d", &op);
		qtd = opt2(op);
		array = (int*)malloc(qtd * sizeof(int));
		
		for(i=0; i<qtd; i++){
			*(array + i) = rand() % qtd;
		}
		
		t1 = clock();
		for(i=0; i<1; i++){
			CoutingSort(array, qtd);
		}
		t2 = clock();
		
	    printf("Vetor ordenado por CoutingSort: ");
	    Exibe_Vetor(array, qtd);
		break;
		
		
		case 7: //bublesort
		
		printf("\nQuantidade de numeros a serem lidos:\nDigite 1 para ler 1000 numeros\nDigite 2 para ler 5000 numeros\nDigite 3 para ler 10000 numeros\nDigite 4 para ler 20000 numeros\nDigite 5 para ler 50000 numeros\nDigite 6 para ler 100000 numeros\n");
		scanf("%d", &op);
		qtd = opt2(op);
		array = (int*)malloc(qtd * sizeof(int));
		
		for(i=0; i<qtd; i++){
			*(array + i) = rand() % qtd;
		}
		t1 = clock();
		for(i=0; i<1; i++){
			bubbleSort(array, qtd);
		}
		t2 = clock();
		
		printArray(array,qtd);		
		
		break;
		case 8://insertionSort
		
		printf("\nQuantidade de numeros a serem lidos:\nDigite 1 para ler 1000 numeros\nDigite 2 para ler 5000 numeros\nDigite 3 para ler 10000 numeros\nDigite 4 para ler 20000 numeros\nDigite 5 para ler 50000 numeros\nDigite 6 para ler 100000 numeros\n");
		scanf("%d", &op);
		qtd = opt2(op);
		array = (int*)malloc(qtd * sizeof(int));
		
		for(i=0; i<qtd; i++){
			*(array + i) = rand() % qtd;
		}
		
		t1 = clock();
		for(i=0; i<1; i++){
			insertionsort(array,qtd);
		}
		t2 = clock();
		
		displayresult(array,qtd);
		break;
		
		case 9://selectionsort
		
		printf("\nQuantidade de numeros a serem lidos:\nDigite 1 para ler 1000 numeros\nDigite 2 para ler 5000 numeros\nDigite 3 para ler 10000 numeros\nDigite 4 para ler 20000 numeros\nDigite 5 para ler 50000 numeros\nDigite 6 para ler 100000 numeros\n");
		scanf("%d", &op);
		qtd = opt2(op);
		array = (int*)malloc(qtd * sizeof(int));
		
		for(i=0; i<qtd; i++){
			*(array + i) = rand() % qtd;
		}
		
		t1 = clock();
		for(i=0; i<1; i++){
			selection(array, qtd);
		}
		t2 = clock();
		
		for(i =0; i<qtd; i++){
			printf("%d ", array[i]);
		}
		break;
		
		case 10: //shellSort
		printf("\nQuantidade de numeros a serem lidos:\nDigite 1 para ler 1000 numeros\nDigite 2 para ler 5000 numeros\nDigite 3 para ler 10000 numeros\nDigite 4 para ler 20000 numeros\nDigite 5 para ler 50000 numeros\nDigite 6 para ler 100000 numeros\n");
		scanf("%d", &op);
		qtd = opt2(op);
		array = (int*)malloc(qtd * sizeof(int));
		
		for(i=0; i<qtd; i++){
			*(array + i) = rand() % qtd;
		}
		
		t1 = clock();
		for(i=0; i<1; i++){
			shellSort(array, 1, qtd);
		}
		t2 = clock();
		
		for(i=0; i<qtd; i++){
			printf("%d ", array[i]);
		}
		break;
		
		case 11: //beadsort
		printf("\nQuantidade de numeros a serem lidos:\nDigite 1 para ler 1000 numeros\nDigite 2 para ler 5000 numeros\nDigite 3 para ler 10000 numeros\nDigite 4 para ler 20000 numeros\nDigite 5 para ler 50000 numeros\nDigite 6 para ler 100000 numeros\n");
		scanf("%d", &op);
		qtd = opt2(op);
		array = (int*)malloc(qtd * sizeof(int));
		
		for(i=0; i<qtd; i++){
			*(array + i) = rand() % qtd;
		}
		
		t1 = clock();
		for(i=0; i<1; i++){
			bead_sort(array,qtd);
		}
		t2 = clock();
		
		for(i=0; i<qtd; i++){
			printf("%d ", array[i]);
		}
		
	}
	float t = (t2 - t1) *1000/ CLOCKS_PER_SEC;
	printf("\n\nTempo de execucao: %f milissegundos", t);
	
	
	free(array);
	
}
