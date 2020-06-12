#include "gemm.h"


int main(int argc, char **argv){
	struct bench_args_t *data = (struct bench_args_t*) malloc(sizeof(struct bench_args_t));
	FILE *m1DataFile = fopen("m1.data", "rt+");
	FILE *m2DataFile = fopen("m2.data", "rt+");
	FILE *outputDataFile = fopen("output.data", "wb");
	FILE *checkDataFile = fopen("check.data", "rt+");
	double temp;
	int i;
	if(m1DataFile==NULL || m2DataFile==NULL){
		printf("read data error.\n");
		return -1;
	}

	for(i=0; i<N; i++){
		fscanf(m1DataFile, "%lf", &data->m1[i]); 
		fscanf(m2DataFile, "%lf", &data->m2[i]); 
	}
	fclose(m1DataFile);
	fclose(m2DataFile);
	for(i=0; i<10000; i++){
		gemm(data->m1, data->m2, data->prod);
	}

	if(outputDataFile==NULL){
		printf("output data error.\n");
		return -1;	
	}
	for(i=0; i<N; i++){
		fprintf(outputDataFile, "%lf\n", data->prod[i]);
	}
	
	fclose(outputDataFile);
	// verify
	if(checkDataFile==NULL){
		printf("read check data error.\n");
		return -1;
	}
	for(i=0; i<N; ++i){
		fscanf(checkDataFile, "%lf", temp);
		if(abs(temp - data->prod[i])>1e-6){
			printf("verify unsuccessed!\n");
			fclose(checkDataFile);
			return 0;
		}	
	}
	fclose(checkDataFile);

	printf("verify successed!\n");
	return 0;
}
