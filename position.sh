zcat  gencode.v19.annotation.gtf.gz | grep   protein_coding |perl -alne '{next unless $F[2] eq "gene" ;/gene_name \"(.*?)\";/; print "$F[0]\t$F[3]\t$F[4]\t$1" }' >protein_coding.hg37.position

perl -p -i -e 's/ /\t/g' RBP_sig7.bed

#bedtools intersect -a RBP_sig7.bed  -b /restricted/projectnb/casa/mtLin/RBP_SNP/768/protein_coding.hg37.position  -wa -wb | bedtools groupby -i - -g 1-4 -c 7 -o collapse >RBP_sig7_gene.tsv

bedtools intersect -a RBP_sig7.bed  -b /restricted/projectnb/casa/mtLin/RBP_SNP/768/protein_coding.hg37.position  -wa -wb > RBP_sig7_gene.tsv

