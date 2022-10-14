#include <iostream>
using namespace std;

int main(){
setlocale(LC_ALL, "Portuguese");
    int numeroPessoas=0, idade=0, somaIdade=0, genero=0, mediaFem=0, quantidadeFem=0, sintomas=0, diasSintomas=0, somaDias=0, mediaDias=0, ajudaMedica=0, quantidadeAjudaMed=0, testeCovid=0, quantidadeSintomaticos=0, quantidadeAssintomaticos=0, covidResultado=0;
	float quantidadeIdadeIdoso=0, porcentagemIdade=0, quantidadeIdosoEmergencia=0;
	
	cout << "\n#### Participe da pesquisa sobre Covid-19 ####\n";
	cout << "\n\nDigite a quantidade de pessoas que participaram da pesquisa: ";
	cin >> numeroPessoas;
    for (int i = 0; i < numeroPessoas; i++)	{
        
        //dados (idade, genero)
		cout << "\nDigite a sua Idade: ";
		cin >> idade;

		cout << "\nSelecione seu genero: ";
	    cout << "1 - Masculino, 2 - Feminino\n" << endl;
		cin >> genero;

        //sintomas
		cout << "\nTeve sintomas de Covid-19?\n";
		cout << "\n1 - sim, 2 - nao\n";
		cin >> sintomas;
		if (sintomas == 1) {
			quantidadeSintomaticos++;
			cout << "\nQuantos dias de sintomas? \n";
			cin >> diasSintomas;
			somaDias += diasSintomas;
		    cout << "\nProcurou ajuda medica? (1- emergencia, 2- Consulta medica, 3- nao) \n";
			cin >> ajudaMedica;

		}
		
		//teste de covid
		cout << "\nRealizou algum teste de Covid?\n";
		cout << "\n1 - sim, 2 - nao\n";
		cin >> testeCovid;

		if (testeCovid == 1) {
			cout << "\nQual foi o resultado?\n";
			cout << "\n1- positivo, 2 - negativo\n";
			cin >> covidResultado;
		}
        
        //operações
		if (covidResultado == 1 && sintomas == 2) {
			quantidadeAssintomaticos++;
		}

		if (idade > 65) {
			quantidadeIdadeIdoso++;
		}

		if (idade > 65 && ajudaMedica == 1) {
			quantidadeIdosoEmergencia++;
		}

		if (sintomas == 1 && ajudaMedica == 3) {
			quantidadeAjudaMed++;
		}
		if (genero == 2 && sintomas == 1 && testeCovid == 2) {
			somaIdade += idade;
			quantidadeFem++;
		}
		
		cout << "\n........................................................................................................\n";
		
    }
    
    
	if (quantidadeSintomaticos != 0) {
		mediaDias = somaDias / quantidadeSintomaticos;
	}
	
	if (quantidadeIdadeIdoso != 0) {
		porcentagemIdade = (quantidadeIdosoEmergencia / quantidadeIdadeIdoso)*100;
	}
	
	if (quantidadeFem != 0) {
		mediaFem = somaIdade / quantidadeFem;
	}
	
	cout << "\n#### Resultados #####\n";
	
	//interface
	cout << "\nQuantidade de assintomaticos: \n" << quantidadeAssintomaticos;
	
	cout << "\nPercentual de pessoas com mais de 65 anos que procuraram atendimento de emergenncia: \n" << porcentagemIdade << "%";
	
	cout << "\nA media de duração dos sintomas do corona­virus entre todos os entrevistados da pesquisa: \n" << mediaDias;
	
	cout << "\nA quantidade de pessoas que tiveram sintomas e não precisaram procurar de ajuda medica: \n" << quantidadeAjudaMed;
	
	cout << "\nA media de idade das mulheres sintomaticas com o teste deu negativo: \n" << mediaFem;

	return 0;
}
