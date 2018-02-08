<?php
class orthoFinderImporter extends TripalImporter {

  /**
   * The name of this loader.  This name will be presented to the site
   * user.
   */
  public static $name = 'OrthoMCL Loader';

  /**
   * The machine name for this loader. This name will be used to construct
   * the URL for the loader.
   */
  public static $machine_name = 'chado_orthomcl_loader';

  /**
   * A brief description for this loader.  This description will be
   * presented to the site user.
   */
  public static $description = 'Load orthoMCL group assignments';

  /**
   * An array containing the extensions of allowed file types.
   */
  public static $file_types = ['txt'];


  /**
   * Provides information to the user about the file upload.  Typically this
   * may include a description of the file types allowed.
   */
  public static $upload_description = 'Please provide the orthoMCL file.';

  /**
   * The title that should appear above the file upload section.
   */
  public static $upload_title = 'orthoMCL loader';

  /**
   * Text that should appear on the button at the bottom of the importer
   * form.
   */
  public static $button_text = 'Import file';


  /**
   * Indicates the methods that the file uploader will support.
   */
  public static $methods = [
    // Allow the user to upload a file to the server.
    'file_upload' => TRUE,
    // Allow the user to provide the path on the Tripal server for the file.
    'file_local' => TRUE,
    // Allow the user to provide a remote URL for the file.
    'file_remote' => TRUE,
  ];

  /**
   * @see TripalImporter::form()
   */
  public function form($form, &$form_state) {

    return $form;
  }

  /**
   * @see TripalImporter::formValidate()
   */
  public function formValidate($form, &$form_state) {

  }

  /**
   * @see TripalImporter::run()
   */
  public function run() {

    $arguments = $this->arguments['run_args'];
    $file_path = $this->arguments['files'][0]['file_path'];

  }
}

//Some thoughts:
//We need to know the type of group we're creating.
//This could be a regular collection, or it could be orthologs.
//I dont know that we'll have that information explicitly or if we'll have to infer it.
