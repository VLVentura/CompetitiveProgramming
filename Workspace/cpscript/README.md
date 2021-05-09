# Como usar

**Deixe apenas um source file no diretório.**

* Se for usar ```Java```, o nome do arquivo precisar ser ```Main.java``` e, consequentemente, a classe principal precisa ter o nome ```Main```. Como é um padrão usado pelos juízes online, eu decidi manter o mesmo padrão.

## Requisitos

1. **BeautifulSoup4**: 

    ```bash
    pip install beautifulsoup4
    ```

2. **Requests**:

    ```bash
    pip install requests
    ```

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

1. ```-h``` ```--help``` Exibe todas as flags e a descrição de cada uma.

2. ```-c``` ```--compile``` Compila o arquivo ```.cpp``` ou ```.java``` do diretório.

3. **[OPÇÃO PARA C++]** ```-v=14``` ```--version=14``` Compila o arquivo ```.cpp``` com a versão informada.

    * Por padrão essa opção esta ```14```.  As opções são: ```11```,  ```14``` e ```17```.

    Se você quiser que mudar a versão padrão, vá ao arquivo ```src/util/settings.json``` e mude a linha abaixo para alguma das 3 opções acima.

    ```json
        6   "default_version": "14"
    ```

4. **[OPÇÃO PARA C++]** ```-pd=0``` ```--pedantic=0``` Compila o arquivo ```.cpp``` com a flag ```-pedantic```. 

    * Por padrão essa opção esta ```false```.  As opções são: ```true (1)``` ou ```false (0)```.

    Se você quiser que mudar para sempre estar habilitada, vá ao arquivo ```src/util/settings.json``` e mude a linha abaixo para ```true```.

    ```json
        7   "pedantic": false
    ```

5. ```-r``` ```--run``` Executa o programa.

6. ```-tin``` ```--test-in``` Executa o programa com a entrada redirecionada para o arquivo ```in.in``` e saída padrão.

7. ```-tout``` ```--test-out``` Executa o programa com a entrada redirecionada para o arquivo ```in.in``` e saída redirecionada para o arquivo ```out.out```.

8. ```-cmp``` ```--compare``` Compara os arquivos ```out.out``` e ```cmp.out```.

    Podem entender a saída do comando [nesse](http://www.bosontreinamentos.com.br/linux/como-comparar-arquivos-no-linux-com-cmp-comm-diff-e-sdiff/) site.

     Se usar __linux__, recomendo instalar o __colordiff__ e usa-lo em vez do __diff__, pode ser instalado por meio do gerenciador de pacote da sua distribuição. Se usar uma distribuição Debian/Ubuntu:

    ```bash
    sudo apt install colordiff
    ```
    vá no arquivo ```src/util/settings.json``` e substitua os comandos ```diff``` para ```colordiff```.
     
    ```json
        47  "execute" : "diff out.out cmp.out"
        48  "command": "diff"
    ```

9. ```-mkfiles``` ```-make-files``` Cria os arquivos ```in.in```, ```out.out``` e ```cmp.out```.

10. ```-rmfiles``` ```--remove-files``` Remove os arquivos ```in.in```, ```out.out```, ```cmp.out```, ```problem (.exe, no caso do windows)```, ```*.class``` e ```LOG.txt```.

11. ```-sv <nome do arquivo>``` ```--save-file <nome do arquivo>``` Irá salvar o arquivo com o nome que você passou para diretório que você irá especificar. Vá ao arquivo ```src/util/settings.json``` e especifique o diretório.

    ```json
        2   "path": "<insira aqui>"
    ```

    * OBS:
        1. No ```Linux```: o caminho do arquivo deve ser no formato ```foo/bar/```
        2. No ```Windows```: deve ser no fomato ```C:\\foo\\bar``` 
    
    * OBS:
        Se o seu caminho tiver espaços no nome:
        1. ```Linux```:

            ```json
                2   "path": "foo/bar/\"pasta com espaco\""
            ```
        2. ```Windows```:

            ```json
                2   "path": "\"C:\\foo\\bar\\pasta com espaco\""
            ```

12. ```-cp``` ```--copy-file``` Irá copiar o arquivo para o diretório que você irá especificar. Vá ao arquivo ```src/util/settings.json``` e especifique o diretório.

13. ```-uri <problema>``` ```--uri-judge``` Irá criar o diretório ```TestCases/Uri/<problema>``` com os casos de teste do problema.

14. ```-cf <problema>``` ```--code-forces``` Irá criar o diretório ```TestCases/CodeForces/<problema>``` com os casos de teste do problema.

15. ```-uva <problema>``` ```--uva-judge``` Irá criar o diretório ```TestCases/Uva/<problema>``` com os casos de teste do problema.

16. ```-tc <judge> <poblem>``` ```--test-cases <judge> <poblem>``` Testa os casos de teste do problema no seu algoritmo e compara com a saída esperada. Se o seu algoritmo não passar em algum dos casos teste, o arquivo ```LOG.txt``` será criado, mostrando as diferenças da saída esperada e a saída apresentada pelo seu algoritmo.

* OBS: Mais de uma flag pode ser combinada, so precisa respeitar a ordem, não adianda testar algo que não compilado ainda!

## Exemplos

### Linux

```bash
python3 run.py -c -tout -cmp
```
```bash
python3 run.py -c -r
```
```bash
python3 run.py -c -cmp
```
```bash
python3 run.py -sv Teste
```

```bash
python3 run.py -c -uri 1001 -tc uri 1001
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

```bash
python run.py -c -uri 1001 -tc uri 1001
```
