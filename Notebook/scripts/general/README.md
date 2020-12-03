# Como usar

## Método 1

```bash
python3 ./run.py <flags>
```

## Método 2

Você pode especificar o caminho do seu interpretador  na __1ª Linha__ do arquivo __run.py__ e executar o arquivo apenas com ```./run.py```.

### Exemplo

Arquivo __run.py__:

```py
1 #!/usr/bin/env python3.8
```

Executar:
```bash
./run.py <flags>
```

# Lista de flags

1. ```-c``` ```-compile``` Compilam o arquivo ```.cpp``` do diretório.

2. ```-r``` ```-run``` Rodam o programa no terminal.

3. ```-cmp``` ```-compare``` Comparam o arquivo __out.out__ com o arquivo __cmp.out__ 

    Podem entender a saída do comando [nesse](http://www.bosontreinamentos.com.br/linux/como-comparar-arquivos-no-linux-com-cmp-comm-diff-e-sdiff/) site.

4. ```-tin``` Testa o programa com os dados do arquivo __in.in__.

5. ```-tout``` Testa o programa com os dados do arquivo __in.in__ e a saída direcionada para __out.out__. Se não tiver nenhum dado de entrada no arquivo __in.in__, a saída será redirecionada sem erros para o arquivo __out.out__.

6. ```-mkfiles``` Cria os arquivos __in.in__, __out.out__ e __cmp.out__.

7. ```-rmfiles``` Remove os arquivos __in.in__, __out.out__, __cmp.out__ e __problem__.

8. ```-sv <nome do arquivo>``` Irá salvar o arquivo com o nome que você passou, no diretório que você irá especificar. No arquivo ```mainscript.py```, especifique o caminho como string para a constante ```PATH_TO_SAVE_FILE```.
    
    * OBS: Não combine a flag ```-sv``` com mais nenhuma outra! __Essa__ deve ser usada __sozinha__.
 
* OBS: Mais de uma flag pode ser combinada, so precisa respeitar a ordem, não adianda testar algo que não compilado ainda!



# Exemplos

```bash
python3 ./run.py -c -tout -cmp
```
```bash
python3 ./run.py -c -r
```
```bash
python3 ./run.py -c -cmp
```
```bash
python3 ./run.py -sv Teste
```