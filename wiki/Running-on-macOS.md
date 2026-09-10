> Nota: idioma oficial do OpenFlowKey é português do Brasil.

# Problemas de atualização
 
Ao atualizar, você pode precisar remover manualmente as entradas do OpenFlowKey da seção de acessibilidade em Privacidade e Segurança.

# Firewall do Sequoia e problemas de segurança

O macOS 15 Sequoia introduziu novos recursos de firewall e segurança que [causaram problemas](https://9to5mac.com/2024/09/19/security-bite-macos-sequoias-filewall-is-disrupting-security-tools-and-more/) com alguns apps. O patch 15.0.1 lançado rapidamente ajudou um pouco, mas não resolveu os problemas completamente.

✅ _Para novas instalações do app:_ Os problemas de firewall e segurança do macOS 15 Sequoia já foram corrigidos pela Apple na atualização menor 15.1 (não confundir com o patch 15.0.1). Atualize para a versão 15.1 para resolver os problemas de firewall e segurança.

:warning: _Ao atualizar um app:_ Você precisará remover o app das configurações de firewall do macOS 15 Sequoia e adicioná-lo novamente para que a nova atualização seja permitida.

# Executando o app OpenFlowKey não assinado no macOS

Ainda não assinamos o pacote do app para macOS, então você verá o erro:
> "OpenFlowKey" está danificado e não pode ser aberto.

<img width="274" alt="image" src="https://github.com/user-attachments/assets/23e1d6ee-e922-47cf-a6ea-0a515f366057">

## Solução

1. Primeiro, tente a [solução da Apple](https://support.apple.com/en-gb/guide/mac-help/mh40616/mac).

2. Se não funcionar, tente:
    - macOS 15 ou superior: `xattr -d com.apple.quarantine /Applications/OpenFlowKey.app`
    - macOS 14 ou inferior: `xattr -dr com.apple.quarantine /Applications/OpenFlowKey.app`

3. Você também pode precisar habilitar `openflowkey` além de `OpenFlowKey`:
<img width="512" alt="macOS security settings" src="https://github.com/user-attachments/assets/7ab76129-8ddf-4a30-b308-560f9a423769">

4. Se você não vê `openflowkey`, também pode ser necessário:
    - Abrir o pacote: `open /Applications/OpenFlowKey.app/Contents/MacOS/`
    - Arrastar todos os binários `openflowkey*` para a janela de acessibilidade.

## Outros recursos

Pode ser útil para alguém: [Quill](https://github.com/anchore/quill) é uma ferramenta simples de assinatura e notarização de binários para Mac.
