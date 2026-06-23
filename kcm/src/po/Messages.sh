#!/usr/bin/env bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
packageRoot=".."
outFile="kcm_kscreensystem.pot"

find ${packageRoot} -name '*.cpp' -o -name '*.h' -o -name '*.qml' |sort > "${DIR}/infiles.list"
xgettext --from-code=UTF-8 -C --kde -ci18n -ki18n:1 -ki18nc:1c,2 -ki18np:1,2 -ki18ncp:1c,2,3 \
    -ktr2i18n:1 -kki18n:1 -kki18nc:1c,2 -kki18np:1,2 -kki18ncp:1c,2,3 \
    --files-from=infiles.list --width=200 \
    --package-name="kcm_kscreensystem" --package-version="" \
    -D "${packageRoot}" -D "${DIR}" -o "${outFile}" || { echo "[merge] error xgettext, aborting."; exit 1; }

rm ${DIR}/infiles.list
