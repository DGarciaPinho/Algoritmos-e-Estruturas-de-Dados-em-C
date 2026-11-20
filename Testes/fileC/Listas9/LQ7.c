/*
7. Uma empresa mantém os dados de seu estoque em um arquivo de texto chamado produtos.csv. Cada registro
contém o código, o nome, a quantidade em estoque e o preço unitário de um produto. Os campos são
separados por ponto e vírgula, e a primeira linha contém o cabeçalho, conforme o exemplo:
codigo;nome;quantidade;preco
101;Caderno;8;18.50
205;Caneta;40;3.00
318;Mochila;3;125.00
427;Borracha;15;2.50
539;Estojo;5;32.00
Considere que o arquivo contém entre 1 e 100 produtos, com códigos únicos, quantidades não negativas e
preços positivos. Os nomes possuem até 50 caracteres e não contêm ponto e vírgula nem aspas. Os preços
utilizam ponto como separador decimal.
Desenvolva um programa em C que execute as etapas a seguir.
(a) Definição do registro: defina o tipo Produto, utilizando typedef e uma struct com os campos código (int),
nome (string), quantidade em estoque (int) e preço unitário (double). Reserve espaço no nome para o
caractere terminador de string.
(b) Leitura do arquivo: implemente uma função que receba o nome do arquivo e um vetor de produtos com
capacidade para 100 registros. A função deverá abrir produtos.csv, desconsiderar o cabeçalho, ler os
registros e armazená-los no vetor. Retorne a quantidade de produtos lidos ou -1 caso não seja possível abrir
o arquivo.
(c) Apresentação dos produtos: implemente uma função que receba o vetor e a quantidade de produtos e
apresente os dados de cada produto, incluindo seu valor total em estoque, calculado pela multiplicação da
quantidade pelo preço unitário.
(d) Processamento do estoque: utilizando os registros carregados, calcule e apresente o valor total do estoque,
considerando todos os produtos. Identifique também o produto com o maior preço unitário e apresente seu
código, nome e preço. Em caso de empate, apresente o primeiro encontrado.
(e) Filtragem e gravação: solicite ao usuário uma quantidade mínima desejada em estoque, que deverá ser um
número inteiro maior que zero. Implemente uma função que receba o nome do arquivo de saída, o vetor, a
quantidade de produtos e o mínimo informado. A função deverá gerar reposicao.csv, contendo apenas os
produtos cuja quantidade em estoque seja inferior ao mínimo, preservando a ordem dos registros e o
formato do arquivo original. Grave os preços com duas casas decimais. Caso o arquivo já exista, substitua
seu conteúdo.
(f) Resultado da gravação: a função de gravação deverá retornar a quantidade de produtos gravados ou -1 caso
não seja possível abrir o arquivo de saída. Na função main, utilize esse retorno para apresentar a quantidade
de produtos que precisam de reposição. Se nenhum produto atender ao critério, o arquivo deverá conter
apenas o cabeçalho.
(g) Organização da execução: na função main, execute as etapas na ordem apresentada. Verifique os retornos
das funções antes de prosseguir. Cada arquivo deverá ser fechado na própria função que o abriu.
Para o arquivo de exemplo e uma quantidade mínima de 6 unidades, o conteúdo de reposicao.csv deverá ser:
codigo;nome;quantidade;preco
318;Mochila;3;125.00
539;Estojo;5;32.00
*/ 

