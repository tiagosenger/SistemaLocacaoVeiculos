#include <iostream>
//#include <windows.h>
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

struct Cliente {
    string cpf;
    string nome;
    string DtNascimento;
    string cnh;
};

struct Veiculo {
    string renavam;
    string placa_veiculo;
    string dataRetirada; 
    string horaRetirada; 
    string DataEntrega;
    string horaEntrega;
    string loja_retirada;
};

struct Locacao {
    bool realizada;
    Cliente clienteConf;
    Veiculo veiculoConf;
    string dataRetiradaConf;
    string horaRetiradaConf;
    string dataEntregaConf;
    string horaEntregaConf;
};

void menuinicial();

void limpaTela() {
    system("cls");
}
//------------FUNÇÕES CLIENTES----------------//
void incluirCliente(vector<Cliente>& cliente) {
    Cliente novoCliente;
    string cpf, nomeCliente, data_nascimento, cnh;
    char opcao;
    
    do {
    cout << "Digite o seu nome : ";
    getline(cin, nomeCliente); 
    novoCliente.nome = nomeCliente;

    cout << "Digite o seu CPF: ";
    getline(cin, cpf);
    for( auto it = cliente.begin();
        it != cliente.end();
        it++){
          while(cpf == (*it).cpf){
            cout << "Este cliente ja esta cadastrado! Digite um outro CPF valido" <<endl;
            getline(cin, cpf);
            }
        }
    novoCliente.cpf = cpf;

    cout << "Digite a data de seu nascimento no formato dd/mm/yyyy: ";
    getline(cin, data_nascimento);
    novoCliente.DtNascimento = data_nascimento;

    cout << "Digite a sua CNH: ";
    getline(cin, cnh);
    novoCliente.cnh = cnh;

    cliente.push_back(novoCliente);
    cout << "Deseja adicionar um novo cliente? (s/n)";
    cin >> opcao;
    cin.ignore();
    limpaTela();

    } while (opcao != 'n');
}

void listarCliente(vector<Cliente>& cliente) {
    if(cliente.size() == 0) {
        cout << "Voce deve adicionar um cliente primeiro! " << endl;
        return;
    }
     for( auto it = cliente.begin();
        it != cliente.end();
        it++){
            cout << "Nome do cliente: " << (*it).nome << endl 
                 << "CPF: " << (*it).cpf << endl
                 << "CNH: " << (*it).cnh << endl 
                 << "Data de nascimento: " << (*it).DtNascimento << endl << endl;
        }
}

void excluirCliente(vector<Cliente>& cliente) {
    if(cliente.size() == 0) {
        cout << "Voce deve adicionar um cliente primeiro! " << endl;
        return;
    }
    string cpf;
    cout << "Digite o CPF do cliente que deseja excluir: ";
    cin >> cpf;

    for( auto it = cliente.begin();
        it != cliente.end();
        it++){
            if(cpf == (*it).cpf) {
                cout << "Cliente " << (*it).nome << " excluido da base de dados com sucesso! " <<endl;
                cliente.erase((it));
            };
        }
}

void alterarDadosCliente (vector<Cliente>& cliente) {
    if(cliente.size() == 0) {
        cout << "Voce deve adicionar um cliente primeiro! " << endl;
        return;
    }
    string cpf , novoNome, novaDataNascimento, novaCnh;
    string novoCPF;
    int opcao;
    cout << "Digite o CPF para encontrar o cliente desejado: ";
    cin >> cpf;

    for( auto it = cliente.begin();
        it != cliente.end();
        it++){
            if(cpf == (*it).cpf) {
                cout << "Cliente localizado!"<< endl << endl;
                cout << "Nome do cliente: " << (*it).nome << endl 
                     << "CPF: " << (*it).cpf << endl
                     << "CNH: " << (*it).cnh << endl 
                     << "Data de nascimento: " << (*it).DtNascimento << endl << endl;

                    cout << "Menu de Opçoes: " << endl;
                    cout << "1. Alterar nome" << endl;
                    cout << "2. Alterar CPF" << endl;
                    cout << "3. Alterar CNH" << endl;
                    cout << "4. Alterar data de nascimento" << endl << endl;
                    
                    cout << "Qual dado do cliente voce deseja alterar? ";
                    cin >> opcao;
                    cin.ignore();
                    
                    switch (opcao){
                    case 1:
                        limpaTela();
                        cout << "Digite o novo nome: " << endl;
                        getline(cin, novoNome);                     
                        (*it).nome = novoNome;
                        break;
                    case 2:
                        limpaTela();
                        cout << "Digite o novo CPF: " << endl;
                        getline(cin, novoCPF);                     
                        (*it).cpf = novoCPF;
                        break;
                    case 3:
                        limpaTela();
                        cout << "Digite a nova CNH: " << endl;
                        getline(cin, novaCnh);                     
                        (*it).cnh = novaCnh;
                        break;
                    case 4:
                        limpaTela();
                        cout << "Digite uma nova data de nascimento: " << endl;
                        getline(cin, novaDataNascimento);                     
                        (*it).DtNascimento = novaDataNascimento;
                        break; 
                    default:
                        cout << "Opcao invalida";
                        break;
                    }
            };
        }
    cout << "Cliente alterado com sucesso!" << endl;

}  

void localizarCliente (vector<Cliente>& cliente) {
     if(cliente.size() == 0) {
        cout << "Voce deve adicionar um cliente primeiro! " <<endl;
        return;
    }

     string cpf;
     cout << "Digite o CPF para encontrar o cliente desejado: ";
     cin >> cpf;
     for( auto it = cliente.begin();
        it != cliente.end();
        it++){
            if(cpf == (*it).cpf) {
                cout << "Cliente localizado!"<< endl << endl;
                cout << "Nome do cliente: " << (*it).nome << endl 
                     << "CPF: " << (*it).cpf << endl
                     << "CNH: " << (*it).cnh << endl 
                     << "Data de nascimento: " << (*it).DtNascimento << endl << endl;
            };
        }
}
//------------FUNÇÕES VEÍCULOS----------------//
void incluirVeiculo (vector<Veiculo>& veiculo) {
    Veiculo novoVeiculo;
    string novoRenavam, novaPlacaVeiculo, novaDataRetirada, horaRetirada, novaDataEntrega, horaEntrega, lojaRetirada;
    char opcao;
    
    do {
    cout << "Digite o renavam : ";
    getline(cin, novoRenavam); 
      for( auto it = veiculo.begin();
        it != veiculo.end();
        it++){
          while(novoRenavam == (*it).renavam){
            cout << "Este renavam ja esta cadastrado! Digite um outro renavam valido" <<endl;
            getline(cin, novoRenavam);
            }
        }
    novoVeiculo.renavam = novoRenavam;

    cout << "Digite a placa do veiculo: ";
    getline(cin, novaPlacaVeiculo);
    novoVeiculo.placa_veiculo = novaPlacaVeiculo;

    cout << "Digite a data de retirada do veiculo no formato dd/mm/yyyy: ";
    getline(cin, novaDataRetirada);
    novoVeiculo.dataRetirada = novaDataRetirada;

    cout << "Hora da retirada do veiculo no formato 00:00 : ";
    getline(cin, horaRetirada);
    novoVeiculo.horaRetirada = horaRetirada;

    cout << "Digite a data de entrega no formato dd/mm/yyyy: ";
    getline(cin, novaDataEntrega);
    novoVeiculo.DataEntrega = novaDataEntrega;

    cout << "Digite a hora de entrega no formato 00:00 : ";
    getline(cin, horaEntrega);
    novoVeiculo.horaEntrega = horaEntrega;

    cout << "Digite a loja onde o veiculo vai ser retirado: ";
    getline(cin, lojaRetirada);
    novoVeiculo.loja_retirada = lojaRetirada;

    veiculo.push_back(novoVeiculo);
    cout << "Deseja adicionar um novo veiculo? (s/n)";
    cin >> opcao;
    cin.ignore();
    limpaTela();

    } while (opcao != 'n');
}

void listarVeiculo(vector<Veiculo>& veiculo) {
      if(veiculo.size() == 0) {
        cout << "Voce deve adicionar um veiculo primeiro! " <<endl;
        return;
    }
     for( auto it = veiculo.begin();
        it != veiculo.end();
        it++){
            cout << "Renavam do veiculo: " << (*it).renavam << endl 
                 << "Placa do veiculo: " << (*it).placa_veiculo << endl
                 << "Data de retirada: " << (*it).dataRetirada << endl 
                 << "Hora de retirada: " << (*it).horaRetirada << endl
                 << "Data de entrega: " << (*it).DataEntrega << endl 
                 << "Hora de entrega: " << (*it).horaEntrega << endl 
                 << "Retirar na loja: " << (*it).loja_retirada << endl << endl;
        }
}

void localizarVeiculo (vector<Veiculo>& veiculo) {
       if(veiculo.size() == 0) {
        cout << "Voce deve adicionar um veiculo primeiro! " <<endl;
        return;
    }

     string placa;
     cout << "Digite a Placa para encontrar o veiculo desejado: ";
     cin >> placa;
     for( auto it = veiculo.begin();
        it != veiculo.end();
        it++){
            if(placa == (*it).placa_veiculo) {
                cout << "Veiculo localizado!"<< endl << endl;
                cout << "Nome do veiculo: " << (*it).renavam << endl 
                 << "Placa do veiculo: " << (*it).placa_veiculo << endl
                 << "Data de retirada: " << (*it).dataRetirada << endl 
                 << "Hora de retirada: " << (*it).horaRetirada << endl
                 << "Data de entrega: " << (*it).DataEntrega << endl 
                 << "Hora de entrega: " << (*it).horaEntrega << endl 
                 << "Retirar na loja: " << (*it).loja_retirada << endl << endl;
            };
        }
}

void excluirVeiculo (vector<Veiculo>& veiculo) {
    if(veiculo.size() == 0) {
        cout << "Voce deve adicionar um veiculo primeiro! " << endl;
        return;
    }
    string placa;
    cout << "Digite a placa do veiculo que deseja excluir: ";
    cin >> placa;

    for( auto it = veiculo.begin();
        it != veiculo.end();
        it++){
            if(placa == (*it).placa_veiculo) {
                cout << "Veiculo de placa " << (*it).placa_veiculo << " excluido da base de dados com sucesso! " <<endl;
                veiculo.erase((it));
            };
        }
}

void alterarDadosVeiculo (vector<Veiculo>& veiculo) {
     if(veiculo.size() == 0) {
        cout << "Voce deve adicionar um veiculo primeiro! " << endl;
        return;
    }
    string placa, novoRenavam, novaDataRetirada, novaHoraRetirada, novaDataEntrega, novaHoraEntrega, novaLojaRetirada;
    string novaPlaca;
    int opcao;
    cout << "Digite o CPF para encontrar o cliente desejado: ";
    cin >> placa;

    for( auto it = veiculo.begin();
        it != veiculo.end();
        it++){
            if(placa == (*it).placa_veiculo) {
                cout << "Veiculo localizado!"<< endl << endl;
                cout << "Renavam do veiculo: " << (*it).renavam << endl 
                     << "Placa: " << (*it).placa_veiculo << endl
                     << "Data de retirada: " << (*it).dataRetirada << endl 
                     << "hora de retirada: " << (*it).horaRetirada << endl
                     << "Data de entrega: " << (*it).horaEntrega << endl
                     << "Hora de entrega: " << (*it).horaEntrega << endl
                     << "Loja que sera retirado o veiculo: " << (*it).loja_retirada << endl << endl;
                     
                    cout << "Menu de Opçoes: " << endl;
                    cout << "1. Alterar renavam" << endl;
                    cout << "2. Alterar placa do veiculo" << endl;
                    cout << "3. Alterar data de retirada" << endl;
                    cout << "4. Alterar hora de retirada" << endl;
                    cout << "5. Alterar data de entrega" << endl;
                    cout << "6. Alterar hora de entrega" << endl;
                    cout << "7. Alterar loja para retirada" << endl;
                    
                    cout << "Qual dado do veiculo voce deseja alterar? ";
                    cin >> opcao;
                    cin.ignore();
                    
                    switch (opcao){
                    case 1:
                        limpaTela();
                        cout << "Digite o novo renavam: " << endl;
                        getline(cin, novoRenavam);                     
                        (*it).renavam = novoRenavam;
                        break;
                    case 2:
                        limpaTela();
                        cout << "Digite a nova placa do veiculo: " << endl;
                        getline(cin, novaPlaca);                     
                        (*it).placa_veiculo = novaPlaca;
                        break;
                    case 3:
                        limpaTela();
                        cout << "Digite a nova data de retirada: " << endl;
                        getline(cin, novaDataRetirada);                     
                        (*it).dataRetirada = novaDataRetirada;
                        break;
                    case 4:
                        limpaTela();
                        cout << "Digite uma nova hora de retirada: " << endl;
                        getline(cin, novaHoraRetirada);                     
                        (*it).horaRetirada = novaHoraRetirada;
                        break;
                    case 5:
                        limpaTela();
                        cout << "Digite a nova data entrega: " << endl;
                        getline(cin, novaDataEntrega);                     
                        (*it).DataEntrega = novaDataEntrega;
                        break; 
                    case 6:
                        limpaTela();
                        cout << "Digite a nova hora de entrega: " << endl;
                        getline(cin, novaHoraEntrega);                     
                        (*it).horaEntrega = novaHoraEntrega;
                        break; 
                    case 7:
                        limpaTela();
                        cout << "Digite uma nova loja para retirada do veiculo: " << endl;
                        getline(cin, novaLojaRetirada);                     
                        (*it).loja_retirada = novaLojaRetirada;
                        break;
                    default:
                        cout << "Opcao invalida";
                        break;
                    }
            };
        }
        cout << "Veiculo alterado com sucesso!" << endl;
}
//------------FUNÇÕES LOCAÇAO----------------//
void incluirlocacao (vector<Locacao> &locacao, vector<Cliente> &cliente, vector<Veiculo> &veiculo){

    Locacao novaLocacao;

    string cnh, placa, cpf, nome, dataRetirada;
    int op;
    cout << "Por favor, informe a CNH do cliente: " << endl;
    getline(cin, cnh);
    cout << "Por favor, informe a Placa do Veiculo: " << endl;
    getline (cin, placa);
        for( auto it = veiculo.begin();
        it != veiculo.end();
        it++){
          while(placa != (*it).placa_veiculo){
            cout << "Este veiculo não está cadastrado! Digite 1 para reinserir a placa ou 2 para retornar ao menu" <<endl;
            cin >> op;
            cin.ignore();
            if (op == 1 ){
            cout << "Digite novamente a Placa: " << endl;
            getline(cin, placa);
            } else if ( op == 2){
                break;
            }
        }
       
        novaLocacao.veiculoConf.placa_veiculo = (*it).placa_veiculo;
    }
    cout << "Por favor, informe o CPF do cliente para verificação: " << endl;
    getline (cin, cpf);
      for( auto it = cliente.begin();
        it != cliente.end();
        it++){
          while(cpf != (*it).cpf){
            cout << "Este cliente não está cadastrado! Digite 1 para reinserir o CPF ou 2 para retornar ao menu" <<endl;
            cin >> op;
            cin.ignore();
            if (op == 1 ){
            cout << "Digite novamente o CPF: " << endl;
            getline(cin, cpf);
            } else if ( op == 2){
                break;
            }
        }
        novaLocacao.clienteConf.nome = (*it).nome;
        novaLocacao.clienteConf.cpf = (*it).cpf;
        novaLocacao.clienteConf.cnh = (*it).cnh;
    }

    cout << "Digite a data real (nao prevista) da retirada: ";
    cin >> dataRetirada;

    locacao.push_back(novaLocacao);
}
//------------FUNÇÕES MENUS------------------//
void menuCliente(vector<Cliente> &cliente) {
    int opcao;
        while(opcao != 0) {
        cout << "Menu de Opcoes: " << endl;
        cout << "1. Incluir cliente" << endl;
        cout << "2. Excluir cliente" << endl;
        cout << "3. Alterar (apenas por CPF) do cliente" << endl;
        cout << "4. Listar cliente" << endl;
        cout << "5. Localizar (apenas por CPF) cliente" << endl;
        cout << "0. Sair" << endl;

        cout << "Escolha uma opcao (de 1 a 5), ou 0 (zero) para sair: ";
        cin >> opcao;  
        cin.ignore();

        switch (opcao){
        case 1:
            limpaTela();
            cout << "Incluir um cliente: " << endl;
            incluirCliente(cliente);
            break;
        case 2:
            limpaTela();
            cout << "Excluir um cliente: " << endl;
            excluirCliente(cliente);
            break;
        case 3:
            limpaTela();
            cout << "Alterar dados de um cliente (por CPF): " << endl;
            alterarDadosCliente(cliente);
            break;
        case 4:
            limpaTela();
            cout << "Listar clientes: " << endl;
            listarCliente(cliente);
            break;
        case 5:
            limpaTela();
            cout << "Localizar um cliente (Por CPF): " << endl;
            localizarCliente(cliente);
            break;  
        default:
            cout << "Programa finalizado";
            break;
        }
    }
}

void menuVeiculo (vector<Veiculo> &veiculo) {
        int opcao;
        while(opcao != 0) {

        cout << "Menu de Opcoes: " << endl;
        cout << "1. Incluir veiculo" << endl;
        cout << "2. Excluir veiculo (apenas por placa do veiculo)" << endl;
        cout << "3. Alterar (apenas por placa) veiculo" << endl;
        cout << "4. Listar veiculo" << endl;
        cout << "5. Localizar (apenas por placa) veiculo" << endl;
        cout << "0. Sair" << endl;

        cout << "Escolha uma opcao (de 1 a 5), ou 0 (zero) para sair: ";
        cin >> opcao;  
        cin.ignore();

        switch (opcao){
        case 1:
            limpaTela();
            cout << "Incluir um veiculo: " << endl;
            incluirVeiculo(veiculo);
            break;
        case 2:
            limpaTela();
            cout << "Excluir um veiculo: " << endl;
            excluirVeiculo(veiculo);
            break;
        case 3:
            limpaTela();
            cout << "Alterar dados de um veiculo (por RENAVAM): " << endl;
            alterarDadosVeiculo(veiculo);
            break;
        case 4:
            limpaTela();
            cout << "Listar veiculos: " << endl;
            listarVeiculo(veiculo);
            break;
        case 5:
            limpaTela();
            cout << "Localizar um veiculo (Por Placa): " << endl;
            localizarVeiculo(veiculo);
            break;  
        default:
            cout << "Programa finalizado";
            break;
         }
    }
}

void menuLocacao (vector<Locacao> &locacao, vector<Cliente> &cliente, vector<Veiculo> &veiculo) {
        int opcao;
        while(opcao != 0) {
        cout << "Menu de Opcoes: " << endl;
        cout << "1. Incluir locacao" << endl;
        cout << "2. Excluir excluir locacao" << endl;
        cout << "3. Alterar locacao" << endl;
        cout << "4. Listar todas as locacoes" << endl;
        cout << "0. Sair" << endl;

        cout << "Escolha uma opcao (de 1 a 5), ou 0 (zero) para sair: ";
        cin >> opcao;  
        cin.ignore();

        switch (opcao){
        case 1:
            limpaTela();
            cout << "Incluir uma locação: " << endl;
            incluirlocacao(locacao, cliente, veiculo);
            break;
        case 2:
            limpaTela();
            cout << "Excluir um veiculo: " << endl;
            excluirVeiculo(veiculo);
            break;
        case 3:
            limpaTela();
            cout << "Alterar dados de um veiculo (por RENAVAM): " << endl;
            alterarDadosVeiculo(veiculo);
            break;
        case 4:
            limpaTela();
            cout << "Listar veiculos: " << endl;
            listarVeiculo(veiculo);
            break;
        case 5:
            limpaTela();
            cout << "Localizar um veiculo (Por Placa): " << endl;
            localizarVeiculo(veiculo);
            break;  
        default:
            cout << "Programa finalizado";
            break;
         }
    }
}
//---------------FUNÇÃO MAIN------------------//
int main () {
    int menu;
    vector<Cliente> cliente;
    vector<Veiculo> veiculo;
    vector<Locacao> locacao;

   do { 
    cout << "Menu de Opcoes: " << endl;
    cout << "1. Gestao de clientes" << endl;
    cout << "2. Gestao de veiculo" << endl;
    cout << "3. Gestao de locacao" << endl << endl;

    cout << "Qual menu voce deseja escolher? ";
    cin >> menu;
    cin.ignore();
    //limpaTela();
    switch(menu){
        case 1:
        menuCliente(cliente);
        break;
        case 2:
        menuVeiculo(veiculo);
        break;
        case 3:
        menuLocacao(locacao, cliente, veiculo);
        break;
        default: 
        cout << "Programa finalizado" << endl;
        break;
    } 
   } while(menu != 0);
   
    return 0;
    
}