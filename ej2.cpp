int main(){
//	genkidama();
	return 0;
}

void genkidama(int T, int N, E enemigos){
	conj atacados;
	int j = 1;
	obj = E[0];
	genki = 0;
	while(j <= N){

		while((j <= N) && (E[j][y] + T <= obj[y])){
			j++;
		}
		atacados.add(E[j-1]);
		genki ++;
		dis = E[j-1][x] + T;
		i = j
		while((i <= N) && (E[i][x] <= dis)){
			i++;
		}
		if (E[i][x] <= dis){
			j = N;
		}

		obj = E[i];
	}

		//print  de henki
		//print del conjunto de enemigos atacados 

}
