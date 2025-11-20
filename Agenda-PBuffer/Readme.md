Agenda pBuffer

Nome: ian xavier freitas
Turma: M1 AED

Uma agenda de contatos feita SEM usar variáveis, só ponteiros. Tudo fica guardado em um buffer de memória (pBuffer).

3 Casos de Teste com Sucesso

1. Adicionar e Listar: Adicionei 3 pessoas e listei todas - funcionou perfeitamente
2. Buscar por Email: Busquei um email existente e um que não existe - funcionou correto
3. Remover Pessoa: Removi uma pessoa pelo email e verifiquei que saiu da lista - funcionou

O que Funciona

- Adicionar pessoas
- Remover pessoas por email
- Buscar pessoas por email
- Listar todas as pessoas
- Sem vazamento de memória (testado com DrMemory)

O que Não Funciona

- Não valida emails duplicados
- Não salva em arquivo (perde os dados ao sair)