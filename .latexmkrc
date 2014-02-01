$pdflatex = 'xelatex --shell-escape %O %S';
$pdf_previewer = "start evince %O %S";
$pdf_update_method = 0;

$out_dir = 'Output';

add_cus_dep('mp', '1', 0, 'mpost');
sub mpost {
    my $file = $_[0];
    my ($name, $path) =  fileparse( $file );
    pushd( $path );
    my $return = system "mpost $name" ;
    popd();
    return $return;
}
