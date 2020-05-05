//aqzhu
//190415
#include <stdio.h>
#include <stdlib.h>

#define N 15

typedef struct tNode{
	int row, col;
	double data;
	tNode *right, *down;
}Node, *PNode;

typedef struct tMatrix{
	int rows;
	int Nr;
	PNode *headNode;
}LinkedMatrix;

int matrixInit(LinkedMatrix *matrix){
	//Matrix
	matrix->Nr = N;
	matrix->headNode = (PNode*)malloc(sizeof(PNode) * (matrix->Nr));
	if (matrix->headNode == NULL){
		printf("matrix headNode malloc error\n");
		exit(-1);
	}
	matrix->rows = 0;
	//headNode initialize
	for(int i=0;i<N;i++){
		matrix->headNode[i]= NULL;
	} 
	FILE *fp;
	fp = fopen("input.dat", "r+");

	int num;//element number 
	int hrow, hcol;
	double hdata;
	
	fscanf(fp, "%d\n", &num);
	printf("read the input.dat, the number is %d\n", num);
	matrix->Nr = num;
	PNode nowNode;
	for(int i=0;i<num;i++){
		
		fscanf(fp, "%d %d %lf\n", &hrow, &hcol, &hdata);

		if(hrow > matrix->rows){//new rows
			//new node
			PNode hNode = (PNode)malloc(sizeof(Node));
			if (hNode == NULL){
				printf("hNode malloc error\n");
				exit(-1);
			}
			hNode->row = hrow;
			hNode->col = hcol;
			hNode->data = hdata;
			hNode->right = NULL;
			hNode->down = NULL;

			//link
			matrix->rows = hrow;		
			matrix->headNode[matrix->rows-1] = hNode;
			nowNode = hNode;
			
			//printf("%d %d %f   %d\n", nowNode->row, nowNode->col, nowNode->data, matrix->rows);		
		}else{
			PNode hNode = (PNode)malloc(sizeof(Node));
			if (hNode == NULL){
				printf("malloc error\n");
				exit(-1);
			}
			hNode->row = hrow;
			hNode->col = hcol;
			hNode->data = hdata;
			hNode->right = NULL;
			hNode->down = NULL;
			
			//link
			nowNode->right = hNode;
			nowNode = hNode;
			//printf("%d %d %f\n", nowNode->row, nowNode->col, nowNode->data);
		}
	}
	fclose(fp);
	printf("matrix Nr: %d, matrix rows: %d\n", matrix->Nr, matrix->rows);
	return 0;
}

int matrixOut1(LinkedMatrix *matrix){

	for(int i=0;i<(matrix->rows);i++){
		PNode hNode = matrix->headNode[i];
		int gap = 0;
		int nZero = 0;
		while(hNode){
			if(gap < hNode->col){	
				gap = (hNode->col) - nZero;
				//printf("gap = %d\n", gap); 
				for(int j=1;j<gap;j++){
					printf(" %-5d", 0);
					nZero++;
				}	
			}
			printf(" %1.3f", hNode->data);
			nZero++;
			hNode = hNode->right;	
		}
		while(nZero < 15){
			printf(" %-5d", 0);
			nZero++;
		}
		printf("\n");
	}
	return 0;
}

int matrixOut(LinkedMatrix *matrix){
	printf("matrix rows : %d\n", (matrix->rows));
	for(int i = 0; i < (matrix->rows); i++){
		PNode hNode;
		hNode = matrix->headNode[i];
		while(hNode){
			printf("%d\t%d\t%f\n", hNode->row, hNode->col, hNode->data);
			hNode = hNode->right;
		}
	}
	return 0;
}

int matrixTranspose(LinkedMatrix *matrix){
	LinkedMatrix newMatrix;
	newMatrix.Nr = N;
	newMatrix.headNode = (PNode*)malloc(sizeof(PNode) * (newMatrix.Nr));
	newMatrix.rows = 0;
	//headNode initialize
	for(int i=0;i<N;i++){
		newMatrix.headNode[i]= NULL;
	}
	int num = matrix->rows;

	for(int i=0;i<num;i++){
		PNode hNode, nextNode;
		hNode = matrix->headNode[i];
		while(hNode){
			//swap
			int a;
			a = hNode->col;
			hNode->col = hNode->row;
			hNode->row = a;
			nextNode = hNode->right;
			hNode->right = NULL;
			
			//link
			if(newMatrix.headNode[a-1] == NULL){
				newMatrix.rows = (newMatrix.rows > a ? newMatrix.rows : a);		
				newMatrix.headNode[a-1] = hNode;
				//printf("%d\t%d\t%f\n", hNode->row, hNode->col, hNode->data);
			}else{
				//printf("%d\t%d\t%f\n", hNode->row, hNode->col, hNode->data);
				PNode flagNode;
				flagNode =  newMatrix.headNode[a-1];
				while(flagNode->right != NULL){
					flagNode = flagNode->right;
				}
				
				flagNode->right = hNode;
			}
			//printf("%d\t%d\t%f\n", hNode->row, hNode->col, hNode->data);
			hNode = nextNode;
		}
	}
	for(int i=0;i<matrix->rows;i++){
		matrix->headNode[i] = newMatrix.headNode[i];
	}
	return 0;
}

int main(){
	LinkedMatrix matrix;
	matrixInit(&matrix);
	matrixOut1(&matrix);
	printf("matrix tranpose\n");
	matrixTranspose(&matrix);
	matrixOut1(&matrix);
	printf("%d\t%d\n", sizeof(double), sizeof(Node)*17); 
	return 0;
}
