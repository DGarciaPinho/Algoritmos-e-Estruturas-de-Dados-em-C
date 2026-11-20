/*
27. (Processamento de registros em formato textual) Um sistema acadêmico exporta os dados de cada estudante
em uma única string. Os campos do registro são separados pelo caractere ponto e vírgula (;) e apresentam o
seguinte formato:
nome;idade;curso
Por exemplo:
Ana Souza;21;Engenharia de Computacao
Desenvolva um programa em C que leia a quantidade de registros e, em seguida, os registros dos estudantes.
Para cada registro, o programa deverá separar e armazenar os seguintes campos em arranjos separados:
• nome do estudante;
• idade;
• curso.
O campo correspondente à idade deverá ser convertido de string para um valor inteiro. Depois de processar
todos os registros, o programa deverá apresentar:
• o nome, a idade e o curso de cada estudante, em campos separados;
• o nome e a idade do estudante mais velho;
Caso existam dois ou mais estudantes com a maior idade, deverá ser apresentado aquele que aparecer primeiro
na entrada. Considere que:
• serão informados, no máximo, 50 registros;
• cada registro possuirá no máximo 149 caracteres;
• os campos não serão vazios;
• cada registro possuirá exatamente dois caracteres ;;
• os campos nome e curso poderão conter espaços, mas não conterão o caractere ;;
• a idade será representada por um número inteiro válido.
Exemplo de entrada:
4
Ana Souza;21;Engenharia de Computacao
Bruno Lima;24;Sistemas de Informacao
Carla Mendes;22;Engenharia de Computacao
Daniel Alves;24;Ciencia da Computacao
Para o exemplo de entrada apresentado, a seguinte saída é esperada:
*Estudantes:
Nome: Ana Souza       | Idade: 21       | Curso: Engenharia de Computacao
Nome: Bruno Lima      | Idade: 24       | Curso: Sistemas de Informacao
Nome: Carla Mendes    | Idade: 22       | Curso: Engenharia de Computacao
Nome: Daniel Alves    | Idade: 24       | Curso: Ciencia da Computacao

*Estudante mais velho:
Nome: Bruno Lima      | Idade: 24       | Curso: Sistemas de Informacao

Embora Bruno Lima e Daniel Alves possuam a mesma idade, Bruno deverá ser apresentado como o estudante
mais velho porque seu registro aparece primeiro na entrada.
*/

