# Calculadora-Dano-Medio-Tormenta20
Um projeto simples que eu fiz em C++ para calcular o dano médio de um personagem ou ameaça no sistema de RPG de Mesa Tormenta20. (A utilização de struct se deu apenas para eu ver como era a struct em C++, mas taí)

O programa roda completamente no terminal do windows.
Inicialmente você insere a margem de ameaça da sua arma, após isso, seu multiplicador de crítico.
Após informar ambas, chega o momento do valor flat de seu dano. Nesse momento, entra seu atributo, modificadores da arma, bônus, o que for necessário.
E, depois de inserir isso, se pede os dados de dano DA ARMA. Nesse caso lembre-se de inserir apenas o dano da arma, pois isso entrará no crítico do sistema. Dados extras serão inseridos depois. Você pode colocar tanto d8, 1d8, 2d8, da forma como preferir.

Caso seu dano acabei ai, ótimo! Caso não, caso possua dados extras, o código questionará se possui, digitando "s" para sim ou "n" para não.
Caso a resposta seja não, responda se possui outro ataque. Caso não, novamente, fim!
-----
Voltando no tempo, para caso possua dados extras! Você digita "s", para sim, e então, diz quais.
Aqui você pode responder 2d6, 8d8, d10, mas caso possua, por exemplo, 2d10+3d6, digite apenas 2d10, pois, após isso, o código perguntará se possui mais algum, e siga nesse ritmo.
Caso pergunte se você possui mais algum ataque, apenas digite "s" e refaça o que foi feito desde o inicío!
