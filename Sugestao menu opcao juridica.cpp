// Se opcao 1- gerenciamento de clientes:
   // 1 cadastrar cliente
      //1 juridico
      bool achou = false;
                string cpf,cnpj, atuacao, funcao, atualizacao;
                cout << "Insira seu CPF:" << endl;
				getline(cin, cpf);
                //busca cpf do cliente na lista de clientes
                for (auto &Cliente : ListaDeClientes) {
                    if (cpf == Cliente->getCpf()) {
                        achou = true;
                        //DUVIDA : COMO ATRIBUIR OS DADOS QUE JA TEM DO CLIENTE FISICO AO JURIDICO
                        cout << "Insira seu CNPJ:" << endl;
                        getline(cin, cnpj);
                        cout << "Insira seu ramo de  atuacao:" << endl;
                        getline(cin, atuacao);
                        cout << "Insira a data de funcacao:" << endl;
                        getline(cin, funcao);
                        cout << "Insira a data da ultima atualiazacao do contrato social:" << endl;
                        getline(cin, atualizacao);
                        

                        Juridico->setCnpj(cnpj);
                        Juridico->setAtuacao(atuacao);
                        Juridico->setFuncao(funcao);
                        Juridico->setAtualizacao(atualizacao);
                        break;
                    }

                }
                if(!achou)
                    cout << "CPF nao cadastrado! Não é possivel abertura de Pessoa Juridica" << endl;

                break;
            }
     // fisico (seguir com o codigo que tem la)
            