# Como usar

## Windows

```bash
python run.py <flags>
```
## Linux

### Método 1

```bash
python3 ./run.py <flags>
```

### Método 2

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

## Lista de flags

1. ```-c``` ```-compile``` Compilam o arquivo ```.cpp``` do diretório.

2. ```-cpd``` ```-cpedantic``` Compilam o arquivo ```.cpp``` do diretório com a flag ```-pedantic```, que trata __warning__ como erro e não permite compilar.

3. ```-r``` ```-run``` Rodam o programa no terminal.

Estou usando a versão ```-std=c++14```, caso você queira uma outra versão, vá ao arquivo ```scripts/settings.json``` e mude as seguintes linhas para a versão que quiser:


```json
    4   "normal": "g++ -std=c++<insira aqui> -O2 -Wall",
    5   "pedantic": "g++ -std=c++<insira aqui> -O2 -Wall -pedantic"
```


4. ```-cmp``` ```-compare``` Comparam o arquivo __out.out__ com o arquivo __cmp.out__ 

    Podem entender a saída do comando [nesse](http://www.bosontreinamentos.com.br/linux/como-comparar-arquivos-no-linux-com-cmp-comm-diff-e-sdiff/) site.

     Se usar __linux__, recomendo instalar o __colordiff__ e usa-lo em vez do __diff__, pode ser instalado por meio do gerenciador de pacote da sua distribuição. Se usar uma distribuição Debian/Ubuntu:

    ```bash
    sudo apt install colordiff
    ```
    vá no arquivo ```scripts/settings.json``` e substitua a string __command__ do arquivo, pela string abaixo.
     
    ```json
    24 "command": "colordiff out.out cmp.out"
    ```

5. ```-tin``` Testa o programa com os dados do arquivo __in.in__.

6. ```-tout``` Testa o programa com os dados do arquivo __in.in__ e a saída direcionada para __out.out__. Se não tiver nenhum dado de entrada no arquivo __in.in__, a saída será redirecionada sem erros para o arquivo __out.out__.

7. ```-mkfiles``` Cria os arquivos __in.in__, __out.out__ e __cmp.out__.

8. ```-rmfiles``` Remove os arquivos __in.in__, __out.out__, __cmp.out__ e __problem__.

9. ```-sv <nome do arquivo>``` Irá salvar o arquivo com o nome que você passou, no diretório que você irá especificar. No arquivo ```scripts/settings.json```, especifique o caminho, como string, para a string ```path```.

    ```json
        2 "path": "<insira aqui>"
    ```

    * OBS:
        1. No __Linux__ o caminho do arquivo deve ser no formato ```foo/boo/```
        2. No __Windows__ deve ser no fomato ```C:\\foo\\boo``` 
    
    * OBS: Não combine a flag ```-sv``` com mais nenhuma outra! __Essa__ deve ser usada __sozinha__.
 
* OBS: Mais de uma flag pode ser combinada, so precisa respeitar a ordem, não adianda testar algo que não compilado ainda!

## Exemplos

### Linux

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

### Windows

```bash
python run.py -c -tout -cmp
```
```bash
python run.py -c -r
```
```bash
python run.py -c -cmp
```
```bash
python run.py -sv Teste
```