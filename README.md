# Projeto: War Estruturado
**Descrição Geral**

- War Game no paradigma de programação estruturada, utilizando a linguagem C.

- Cada commit será documentado neste arquivo, abordando os objetivos e requisitos implementados.

# Primeiro Commit

**Objetivos**

- Construir uma base de dados de territórios utilizando uma estrutura de dados composta.

- Criar uma struct chamada Territorio que armazenará informações como nome, cor do exército e quantidade de tropas. O sistema permitirá o cadastro de 5 territórios e exibirá seus dados logo após o preenchimento.

**Requisitos Funcionais**

- **Criação da struct:** definir uma struct chamada Territorio com os campos char nome[30], char cor[10] e int tropas.

- **Cadastro dos territórios:** o sistema deve permitir que o usuário cadastre cinco territórios informando o nome, cor do exército e o número de tropas de cada um.

- **Exibição dos dados:** o sistema deve exibir as informações de todos os territórios registrados após o cadastro.

**Requisitos Não Funcionais**

- **Usabilidade:** a interface de entrada deve ser simples e clara, com mensagens que orientem o usuário sobre o que digitar.
 
- **Desempenho:** o sistema deve apresentar os dados logo após o cadastro, com tempo de resposta inferior a 2 segundos.
 
- **Documentação:** o código deve conter comentários explicativos sobre a criação da struct, entrada e exibição de dados.
 
- **Manutenibilidade:** os nomes das variáveis e funções devem ser claros e representativos, facilitando a leitura e manutenção do código.

# Segundo Commit

**Objetivos**

-  Adicionar a funcionalidade de ataque entre os territórios.

-   Com base nos territórios já cadastrados, o sistema deverá permitir que um jogador selecione um território como atacante, e outro como defensor. O ataque será resolvido por meio de uma simulação com dados aleatórios (como rolagem de dados), e o resultado alterará o controle e as tropas do território atacado.

**Requisitos Funcionais**


- **Alocação dinâmica de territórios:** utilizar calloc ou malloc para alocar memória para um vetor de struct Territorio com tamanho informado pelo usuário.
 
- **Simulação de ataques:** criar uma função void atacar(Territorio* atacante, Territorio* defensor) que simula um ataque, utilizando números aleatórios como se fossem dados de batalha.
 
- **Atualização de dados:** o território defensor deve mudar de dono (cor do exército) se o atacante vencer, e suas tropas devem ser atualizadas.
 
- **Exibição pós-ataque:** o sistema deve exibir os dados atualizados dos territórios após cada ataque.

**Requisitos Não Funcionais**

- **Modularização:** o código deve estar organizado com funções distintas para cadastro, exibição, ataque e liberação de memória.
 
- **Uso de ponteiros:** todos os acessos e modificações aos dados dos territórios devem ser feitos por ponteiros.
 
- **Gerenciamento de memória:** toda memória alocada dinamicamente deve ser liberada ao final do programa utilizando free.
 
- **Interface amigável:** o terminal deve orientar o jogador sobre quais territórios podem ser usados para atacar e defender, com mensagens claras.