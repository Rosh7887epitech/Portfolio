folder('Tools') {
    displayName('Tools')
    description('Folder for miscellaneous tools.')
}

job("Tools/clone-repository") {
    wrappers {
        preBuildCleanup {
            includePattern('**/target/**')
            deleteDirectories()
        }
    }
    parameters {
        stringParam('GIT_REPOSITORY_URL', '', 'Git URL of the repository to clone')
    }
    steps {
        shell('git clone ${GIT_REPOSITORY_URL}')
    }
}

job("Tools/SEED") {
  wrappers {
    preBuildCleanup {
      includePattern('**/target/**')
      deleteDirectories()
    }
  }
  parameters {
    stringParam('GITHUB_NAME', '', 'GitHub repository owner/repo_name (e.g.: "EpitechIT31000/chocolatine")')
    stringParam('DISPLAY_NAME', '', 'Display name for the job')
  }
  steps {
    dsl {
      text('''
        job("${DISPLAY_NAME}") {
          wrappers {
            preBuildCleanup {
              includePattern('**/target/**')
              deleteDirectories()
            }
          }

          scm {
            git {
              remote {
                url("https://github.com/\${GITHUB_NAME}.git")
              }
              branch('main')
            }
          }

          properties {
            githubProjectUrl("https://github.com/${GITHUB_NAME}")
          }

          triggers {
            scm('H/1 * * * *')
          }

          steps {
            shell('make fclean')
            shell('make')
            shell('make test_run')
            shell('make clean')
          }
        }
      '''.stripIndent())
    }
  }
}
