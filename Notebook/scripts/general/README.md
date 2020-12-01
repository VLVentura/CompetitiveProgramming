# Como usar

```bash
python3 ./run.py <flags>
```

* OBS: Você pode botar o caminho do seu interpretador  na __1ª Linha__ do arquivo __run.py__ e executar o arquivo apenas com 

```bash
./run.py <flags>
```

## Lista de flags

1. ```-c``` ```-compile``` Compilam o arquivo ```.cpp``` do diretório.

2. ```-r``` ```-run``` Rodam o programa no terminal.

3. ```-cmp``` ```-compare``` Comparam o arquivo __out.out__ com o arquivo __cmp.out__ 

    Podem entender a saída do comando [nesse](http://www.bosontreinamentos.com.br/linux/como-comparar-arquivos-no-linux-com-cmp-comm-diff-e-sdiff/) site.

4. ```-tin``` Testa o programa com os dados do arquivo __in.in__.

5. ```-tout``` Testa o programa com os dados do arquivo __in.in__ e a saída direcionada para __out.out__. Se não tiver nenhum dado de entrada no arquivo __in.in__, a saída será redirecionada sem erros para o arquivo __out.out__. 

* OBS: Mais de uma flag pode ser combinada, so precisa respeitar a ordem, não adianda testar algo que não compilado ainda!

## Exemplo

```bash
python3 ./run.py -c -tout -cmp
```
```bash
python3 ./run.py -c -r
```
```bash
python3 ./run.py -c -cmp
```