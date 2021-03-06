#!/bin/bash
echo "--------------------------------------------"
echo "MUon FAst Simulation Algorithm - MUFASA v1.1"
echo "--------------------------------------------"
 
N_TGT=1       #[number of targets]
L_TGT=0.035     #[m] tgt lenght
L_CELL=5        #[m] fodocell
MATERIALE="be"  #tgt material
NOME_POS0="2750_45GeV.dat" #name of the positron input file
echo "    Target number:   "$N_TGT"     (da 0 a "`expr $N_TGT - 1`")"
echo "    Target lenght:   "$L_TGT
echo "    Target material: "$MATERIALE
echo "    Cell lenght:     "$L_CELL
echo "    Positron file:   "$NOME_POS0

#echo " "
#echo "NOW..."
#echo "Checking soft. requirements :"
#echo "  Checking for root ..."
hash root 2>/dev/null || { echo >&2 "OOOps... I require root but it's not installed.  Aborting."; exit 1; }
#echo "    ... root found"
#echo "  Checking for awk ..."
hash awk 2>/dev/null || { echo >&2 "OOOps... I require awk but it's not installed.  Aborting."; exit 1; }
#echo "    ... akw found"
#echo "  Checking for madx ..."
hash madx 2>/dev/null || { echo >&2 "OOOps... I require madx but it's not installed.  Aborting."; exit 1; }
#echo "    ... madx found"
#echo " "


NOME_POS="pos_"$MATERIALE$N_TGT"tgt_"$L_TGT"m_"$NOME_POS0
rm $NOME_POS
cp "$NOME_POS0" "$NOME_POS"
echo "    File "$NOME_POS" succesfully created."
echo " "

NOME_MU="mu_"$NOME_POS
rm $NOME_MU

echo "   Producing muons and propagating particles"
n_tgt=0  #number of the target i am working on 0<=n_tgt<N_TGT
while [ "$n_tgt" -le "`expr $N_TGT - 1`" ]
do
    root -l -x -q "pos2mu.cxx(\"$NOME_POS\",$n_tgt,$L_TGT,\"$MATERIALE\")"
    madx < ./XFASA/pos.track.ptc.madx
    root -l -x -q "MAD2POS.cxx(\"$NOME_POS\",$n_tgt)"

    madx < ./XFASA/mu.track.ptc.madx
    root -l -x -q "mutrack.cxx($n_tgt)"

    i=`expr $n_tgt + 1`
    while [ "$i" -le "`expr $N_TGT - 1`" ]
    do
	root -l -x -q "MSmuon.cxx($L_TGT,\"$MATERIALE\")"
	madx < ./XFASA/mu.track.ptc.madx
	root -l -x -q "mutrack.cxx($n_tgt)"
	i=$(($i + 1))
    done
    
    root -l -x -q "MAD2MU.cxx(\"$NOME_MU\")"
    
    n_tgt=$(($n_tgt + 1))
done

echo "    Evaluating decay process for muons"
root -l -x -q "DECAYmuon.cxx(\"$NOME_MU\",$N_TGT,$L_TGT,$L_CELL)"
NOME_MU_OUT="out_"$NOME_MU
echo "    file "$NOME_MU_OUT" created"
echo " "

echo "    Moving output files in the ./OUTPUT folder"
mv $NOME_POS ./OUTPUT/$NOME_POS
mv $NOME_MU ./OUTPUT/$NOME_MU
mv $NOME_MU_OUT ./OUTPUT/$NOME_MU_OUT

echo "    Moving *tmp and track* files in the ./TEMP folder"
mv *.tmp ./TEMP/
mv track* ./TEMP/
echo "    The end, ROAR"


