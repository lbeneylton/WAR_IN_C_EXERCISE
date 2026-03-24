# Desafio: nível novato

Este desafio introduz o conceito de structs como ferramenta para agrupar dados relacionados.

## Objetivo

Construir uma **base de dado de territórios** utilizando uma **estrutura de dados composta**.

---

### O que deve ser feito?

Deve existir uma **struct** chamada territorio que irá armazenar informações como *nome*, *cor do exército*, *quantidade de tropas*.
O sistema deve permitir o cadastro de **5 territórios** e exibir seus dados logo após o preenchimento.

## Requisitos Funcionais

- **Cadastro de territórios:** O sistema deve permitir que o usuário cadastre *cinco* territórios informando *nome*, *cor do exército* e o *numero de tropas* de cada um.

- **Exibição dos dados:** O sistema deve exibir as informações de todos os territórios registrados após o cadastro.

---

## Requisitos Não Funcionais

- **Usabilidade:** A interface de entrada deve ser simples e clara com mensagens que orietem o usuário sobre o que digitar.

- **Desempenho:** o sistema deve apresentar os dados logo após o cadastro, com tempo de resposta inferior a 2 segundos.

- **Documentação:** o código deve conter comentários explicativos sobre a criação da struct, entrada e exibição de dados.

- **Manutenibilidade:** os nomes das variáveis e funções devem ser claros e representativos, facilitando a leitura e manutenção do código.

## Instruções detalhadas

- **Bibliotecas necessárias:** inclua as bibliotecas stdio.h e string.h.

- **Definição da struct:** crie a struct Territorio com os campos mencionados.

- **Declaração de vetor de structs:** crie um vetor com capacidade para armazenar 5 estruturas do tipo Territorio.

- **Entrada dos dados:** utilize um laço for para preencher os dados dos 5 territórios.

- **Exibição:** percorra, após o cadastro, o vetor e exiba os dados de cada território com formatação clara.

### Requisitos técnicos adicionais

Algumas orientações adicionais para uma implementação correta e bem documentada:

- Use scanf para ler o nome e o número de tropas.

- Utilize fgets ou scanf("%s", ...) com cuidado para strings.

- Comente seu código explicando a criação e o uso da struct e a lógica do laço de entrada e saída.
