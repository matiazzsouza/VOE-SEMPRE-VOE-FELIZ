Voe Sempre, Voe Feliz ✈️

Descrição do Projeto

O projeto "Voe Sempre, Voe Feliz" é um sistema para gerenciamento de voos em empresas de passagens aéreas. O programa permite a inclusão, alteração, exclusão e consulta de trajetórias de voos, facilitando a administração e organização das operações aéreas.

Objetivo

O sistema foi desenvolvido para auxiliar empresas na gestão de voos, proporcionando:

Melhor organização e administração dos voos.

Acesso rápido às informações dos voos por origem, destino e escalas.

Facilidade na inclusão, edição e remoção de voos.

Funcionalidades 🚀

Adicionar Voos: Cadastra um novo voo com origem, destino, escalas e código identificador.

Excluir Voos: Remove voos da lista de trajetórias ativas.

Alterar Voos: Permite modificar informações de um voo cadastrado.

Consultar Voos: Exibe uma lista de voos filtrada por critérios como cidade de origem ou destino.

Principais Dificuldades e Soluções 💡

Exclusão de Voos: Inicialmente, a equipe tentou reorganizar os espaços vazios no vetor de voos. No entanto, foi mais eficiente marcar voos excluídos com código "0", ignorando-os na exibição.

Organização das escalas: O uso de uma matriz foi adotado, onde cada linha representa uma cidade para armazenar as escalas dos voos.

Tratamento de Erros:

Foi criada a função codigoVooExiste(), que impede a duplicação de voos.

Implementado um laço while para garantir a entrada de valores válidos para escalas.

Como Utilizar 📌

Execute o programa no terminal.

No menu principal, escolha a opção desejada (Adicionar, Excluir, Alterar ou Consultar voos).

Siga as instruções na tela para inserir ou modificar informações.

Para evitar erros, sempre siga os limites definidos pelo sistema ao inserir dados.

Tecnologias Utilizadas 🛠️

Linguagem: C

Estruturas de Dados: Vetores e Matrizes

IDE recomendada: Dev-C++ ou Code::Blocks

Autores 👨‍💻👩‍💻

Lucas Kitsuta Sabino (RA: 24001484)

Mateus Souza Marinho (RA: 24005497)

Otávio Augusto Barros de Brito (RA: 23026886)

Tales Martins de Moraes (RA: 24001032)

Victor Augusto Trevisan de Souza (RA: 24001845)

Referências 📚

Aulas e Atividades do Canvas

GeeksforGeeks - strupr() function in C (Acesso em 23/05/2024)

Stack Overflow - Mudar cor de letras em C (Acesso em 20/05/2024)

