#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>
#include <git2.h>

#define PATHLEN 128

int
main(int argc, char **argv)
{
  int res;
  git_repository *repo;
  git_reference *head;
  char pathbuf[PATHLEN], *branch;

  git_libgit2_init();

  puts("");

  if ((res = git_repository_open_ext(&repo, ".", 0, NULL)) == -1) {
    fprintf(stderr, "git_repository_open_ext: %s\n", git_error_last()->message);
    return EXIT_FAILURE;
  }

  if (!res) {    
    if (git_repository_head(&head, repo) != 0) {
      fprintf(stderr, "git_repository_head: %s\n", git_error_last()->message);
      return EXIT_FAILURE;
    }

    fputs(basename(git_repository_workdir(repo)), stdout);
  } else {
    if (!getcwd(pathbuf, PATHLEN)) {
      perror("getcwd");
      return EXIT_FAILURE;
    }

    fputs(pathbuf, stdout);
  }

  if (!res) {
    if (!(branch = git_reference_name(head))) {
      fprintf(stderr, "git_reference_name: %s\n", git_error_last()->message);
      return EXIT_FAILURE;
    }

    printf(" on %s", &branch[11]);
  }

  fputs("\n$ ", stdout);

  return EXIT_SUCCESS;
}
