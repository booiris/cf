token = input().split('state=')[-1].split('&')[0] 
url = 'https://vscode-auth.github.com/authorize/?callbackUri=vscode://vscode.github-authentication/did-authenticate&scope=repo&state={}&responseType=code' 
print(url.format(toke