# include<stdio.h>
int main(){
	double g = 32.2;
	double L = 3000;
	double F0 = 35.1 * 0.67;
	double h, v, F;
	double density = 62.51;
	double Ap = 7.06;
	double AT = 113;
	double KF = 2.81e-2;
	double gc = 32.2;
	double dvdt,dhdt;
	double time;
	double timestep = 1;
	double timestop = 5000;
	h = 2.05;
	v = 3.4;
	time = 0;
	FILE *fp;
	fp = fopen("result.txt", "w");
	bool change = true;
	do{
		if ((time > 2000) && (change == true)){
			F0 = F0/0.67;
			change = false;
		}
		F = Ap * v;
		dhdt = (F0-F)/AT;
		dvdt = g/L*h - KF*gc/density/Ap*v*v;
		h = h + dhdt*timestep;
		v = v + dvdt*timestep;
		time = time + timestep;
		fprintf(fp, "\n%f\t%f\t%f\t%f", time, h, v, F);
	}while(time < timestop);
	fclose(fp);
	return 0;
	
} 
