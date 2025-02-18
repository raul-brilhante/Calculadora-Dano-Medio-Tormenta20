#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
using namespace std;

struct resultadosFinais {
  double primeiro = 0.0;
  double segundo = 0.0;
  double terceiro = 0.0;
  double quarto = 0.0;
  double quinto = 0.0;
  double sexto = 0.0;
  double setimo = 0.0;
  double oitavo = 0.0;
};

resultadosFinais umDanoAntigoAi;

double calculaDado(string dado) {

  size_t pos = dado.find('d');

  int numDados = 1;
  if (dado[0] != 'd') {
    numDados = stoi(dado.substr(0, pos));
  }
  int valorDado = stoi(dado.substr(pos + 1));

  return ((numDados + (numDados*valorDado)) / 2.0);
}

double verificaDadosExtras() {
  char sOUn;
  int dadosExtras = 0;
  string dadoDanoExtra = "";
  cout << "Digite S para sim e N para não: ";  cin >> sOUn;
  while (sOUn == 'S' || sOUn == 's') {
    cout << "Digite um dado de dano extra: ";  cin >> dadoDanoExtra;
    dadosExtras += calculaDado(dadoDanoExtra);
    cout << endl << "Possue mais algum?" << endl;
    cout << "Digite S para sim e N para não: ";  cin >> sOUn;
  }
  return dadosExtras;
}

resultadosFinais repeticao(resultadosFinais danoAntes) {
  resultadosFinais resultadosRepetidos;
  resultadosRepetidos.primeiro = danoAntes.primeiro + umDanoAntigoAi.primeiro;
  resultadosRepetidos.segundo = danoAntes.segundo + umDanoAntigoAi.segundo;
  resultadosRepetidos.terceiro = danoAntes.terceiro + umDanoAntigoAi.terceiro;
  resultadosRepetidos.quarto = danoAntes.quarto + umDanoAntigoAi.quarto;
  resultadosRepetidos.quinto = danoAntes.quinto + umDanoAntigoAi.quinto;
  resultadosRepetidos.sexto = danoAntes.sexto + umDanoAntigoAi.sexto;
  resultadosRepetidos.setimo = danoAntes.setimo + umDanoAntigoAi.setimo;
  resultadosRepetidos.oitavo = danoAntes.oitavo + umDanoAntigoAi.oitavo;

  return resultadosRepetidos;
}

resultadosFinais calculacao(resultadosFinais danoAntes) {
  int margem = 0, multiplicador = 0, flat = 0;
  string dadosArma = "";
  cout << "Digite a margem de ameaça: ";  cin >> margem;
  cout << "Digite o multiplicador de critico: ";  cin >> multiplicador;
  cout << "Digite o bônus numérico (flat): ";  cin >> flat;
  cout << "Digite os dados de dano da arma: ";  cin >> dadosArma;
  cout << endl << "Possue dados extras a calcular?" << endl;

  double dadosExtra = verificaDadosExtras();
  double danoArma = calculaDado(dadosArma);
  double chanceNaoCritar = (margem - 1.0) * 5.0;
  double chanceCritar = 100.0 - chanceNaoCritar;
  double chanceCritarC = chanceCritar + ((chanceNaoCritar * chanceCritar) / 100.0);
  double chanceNaoCritarC = 100.0 - chanceCritarC;

  resultadosFinais resultadinhos;
  resultadinhos.primeiro = (((((danoArma) + flat + dadosExtra) * (chanceNaoCritar)) + ((((danoArma) * multiplicador) + flat + dadosExtra) * (chanceCritar))) / 100) + danoAntes.primeiro;
  resultadinhos.segundo = ((((danoArma) + flat + dadosExtra) * (chanceNaoCritarC) + (((danoArma) * multiplicador) + flat + dadosExtra) * (chanceCritarC)) / 100) + danoAntes.segundo;
  resultadinhos.terceiro = (((((danoArma) + flat + dadosExtra) * (chanceNaoCritar)) + ((((danoArma) * multiplicador) + flat + 10 + dadosExtra) * (chanceCritar))) / 100) + danoAntes.terceiro;
  resultadinhos.quarto = ((((danoArma) + flat + dadosExtra) * (chanceNaoCritarC) + (((danoArma) * multiplicador) + flat + 10 + dadosExtra) * (chanceCritarC)) / 100) + danoAntes.quarto;
  resultadinhos.quinto = (((((danoArma) + flat + dadosExtra) * (chanceNaoCritar)) + (((((danoArma) + flat) * multiplicador) + dadosExtra) * (chanceCritar))) / 100) + danoAntes.quinto;
  resultadinhos.sexto = ((((danoArma) + flat + dadosExtra) * (chanceNaoCritarC) + ((((danoArma) + flat) * multiplicador) + dadosExtra) * (chanceCritarC)) / 100) + danoAntes.sexto;
  resultadinhos.setimo = (((((danoArma) + flat + dadosExtra) * (chanceNaoCritar)) + (((((danoArma) + 10) * multiplicador) + flat + dadosExtra) * (chanceCritar))) / 100) + danoAntes.setimo;
  resultadinhos.oitavo = ((((danoArma) + flat + dadosExtra) * (chanceNaoCritarC) + ((((danoArma) + 10) * multiplicador) + flat + dadosExtra) * (chanceCritarC)) / 100) + danoAntes.oitavo;

  umDanoAntigoAi.primeiro = (((((danoArma) + flat + dadosExtra) * (chanceNaoCritar)) + ((((danoArma) * multiplicador) + flat + dadosExtra) * (chanceCritar))) / 100);
  umDanoAntigoAi.segundo = ((((danoArma) + flat + dadosExtra) * (chanceNaoCritarC) + (((danoArma) * multiplicador) + flat + dadosExtra) * (chanceCritarC)) / 100);
  umDanoAntigoAi.terceiro = (((((danoArma) + flat + dadosExtra) * (chanceNaoCritar)) + ((((danoArma) * multiplicador) + flat + 10 + dadosExtra) * (chanceCritar))) / 100);
  umDanoAntigoAi.quarto = ((((danoArma) + flat + dadosExtra) * (chanceNaoCritarC) + (((danoArma) * multiplicador) + flat + 10 + dadosExtra) * (chanceCritarC)) / 100);
  umDanoAntigoAi.quinto = (((((danoArma) + flat + dadosExtra) * (chanceNaoCritar)) + (((((danoArma) + flat) * multiplicador) + dadosExtra) * (chanceCritar))) / 100);
  umDanoAntigoAi.sexto = ((((danoArma) + flat + dadosExtra) * (chanceNaoCritarC) + ((((danoArma) + flat) * multiplicador) + dadosExtra) * (chanceCritarC)) / 100);
  umDanoAntigoAi.setimo = (((((danoArma) + flat + dadosExtra) * (chanceNaoCritar)) + (((((danoArma) + 10) * multiplicador) + flat + dadosExtra) * (chanceCritar))) / 100);
  umDanoAntigoAi.oitavo = ((((danoArma) + flat + dadosExtra) * (chanceNaoCritarC) + ((((danoArma) + 10) * multiplicador) + flat + dadosExtra) * (chanceCritarC)) / 100);

  return resultadinhos;
}

int main() {
  system("chcp 65001");
  cout << "Bem vinde ao calculador de dano médio de RaumiNiji!" << endl;
  cout << "Deu trabalho então espero que tire bom proveito!" << endl << endl;

  char maisUmAtaque = 's';
  char mesmoAtaque = 'n';
  resultadosFinais resultados;
  while (maisUmAtaque == 's' || maisUmAtaque == 'S') {
    if (resultados.primeiro != 0.0) {
      cout << endl << "Por algum acaso, é o mesmo ataque anterior? "; cin >> mesmoAtaque;
      if (mesmoAtaque == 's' || mesmoAtaque == 'S') {
        resultados = repeticao(resultados);
      }
      else {
        resultados = calculacao(resultados);
      }
    }
    else {
      resultados = calculacao(resultados);
    }
    cout << endl << "Possue mais algum ataque? S ou N?: "; cin >> maisUmAtaque;
  }

  cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "Dano normal: " << resultados.primeiro << endl;
  cout << "Dano com concentração de combate: " << resultados.segundo << endl << endl;
  cout << "Dano normal com dilacerante: " << resultados.terceiro << endl;
  cout << "Dano com concentração de combate com dilacerante: " << resultados.quarto << endl << endl;
  cout << "Dano normal com lancinante: " << resultados.quinto << endl;
  cout << "Dano com concentração de combate com lancinante: " << resultados.sexto << endl << endl;
  cout << "Dano normal com lancinante revisado: " << resultados.setimo << endl;
  cout << "Dano com concentração de combate com lancinante revisado: " << resultados.oitavo << endl;

  char antesDeTerminar;
  cout << "Digite qualquer tecla para fechar: "; cin >> antesDeTerminar;

  return 0;
}
